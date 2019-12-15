from Card import Card
from Deck import Deck
from Player import Player
from Pile import Pile
import json
import random


class Game:
        def __init__(self, players):

                self.deck = Deck()
                self.deck.shuffle()
                self.players = players
                self.players.sort()
                self.turn = 0
                self.direction = 1
                self.currentPlayerIndex = 0
                self.currentPlayer = self.players[self.currentPlayerIndex]
                self.maxpiles = 4                                                       # This 'needs' to be a constant
                self.piles = []
                self.finished = False



                for i in range(self.maxpiles):
                        self.piles.append(Pile())

                while(True):
                        pileCard = self.deck.drawCard()
                        if not pileCard.isSpecial:
                                break
                        else:
                                self.deck.cards.append(pileCard)
                                random.shuffle(self.deck.cards)

                self.piles[0].addCard(pileCard)


                for player in self.players:
                        for x in range(0, 2):
                            player.addCard(self.deck.drawCard())


        def performAction(self, action):

                self.players.sort()
                self.currentPlayerIndex = self.players.index(self.currentPlayer)
                if action[0] == 0:
                        # draw card
                        self.players[self.currentPlayerIndex].addCard(self.deck.drawCard())
                elif action[0] == 1:
                        # play card
                        tmp = self.currentPlayerIndex
                        cardPlayed = self.players[self.currentPlayerIndex].removeCard(action[1])
                        if not checkCardCompatibility(self.piles[action[2]].topCard, cardPlayed):
                            exit("Error: Card played was not found in hand. Cheating??")

                        removedCard = self.piles[action[2]].addCard(cardPlayed)
                        #perform card functionalities
                        self.performSpecial(action, cardPlayed)
                        if not cardPlayed.isSpecial:
                            self.advanceTurn()

                        if (len(self.players[tmp].hand) == 0):
                            self.finished = True

                elif action[0] == 2:
                        return False

                return True

        def advanceTurn(self):
                self.currentPlayerIndex += self.direction
                self.currentPlayerIndex = self.currentPlayerIndex % len(self.players)
                self.currentPlayer = self.players[self.currentPlayerIndex]

        def getPiles(self):
                return self.piles

        def addPile(self, pilePlayedOn):
            while(True):
                    pileCard = self.deck.drawCard()
                    if not pileCard.isSpecial:
                        self.piles[pilePlayedOn].addCard(pileCard)
                        break
                    else:
                            self.deck.cards.append(pileCard)
                            random.shuffle(self.deck.cards)

        def swapHands(self, firstPlayerID, secondPlayerID):
                temp = self.players[firstPlayerID].hand
                self.players[firstPlayerID].hand = self.players[secondPlayerID].hand
                self.players[secondPlayerID].hand = temp

        def swapHandsDirection(self, direction):
                if(direction == 1):
                        for x in range(1, len(self.players)):
                                self.swapHands(0, x)
                else:
                        for x in range (len(self.players)-1, 0, -1):
                                self.swapHands(0, x)

        def drawUntilColor(self, playerID, color):
                drawnCard = self.deck.drawCard()
                self.players[playerID].addCard(drawnCard)
                while(drawnCard.color != color):
                        drawnCard = self.deck.drawCard()
                        self.players[playerID].addCard(drawnCard)

        '''
        Card Detail List:
        skip
        reverse
        draw2
        draw4
        wild
        allDrawRandom
        drawUntilColor
        swapHands
        swapHandsDirection
        addPile
        '''
        #Im assuming action[3] is where the color is passed in
        #1 = red, 2 = yellow, 3 = green, 4 = blue and 0 is default
        def performSpecial(self, action, card):
            #get action[3] value for color so that color dependent cards can use it

            #perform special card action
            if card.isSpecial:
                if card.details == "skip":
                    self.advanceTurn()
                    self.advanceTurn()
                elif card.details == "reverse":
                    if(self.direction == 1):
                            self.direction = -1
                    else:
                            self.direction = 1
                    self.advanceTurn()
                elif card.details == "draw2":
                    self.advanceTurn()
                    for x in range(0,2):
                        drawnCard = self.deck.drawCard()
                        self.players[self.currentPlayerIndex].addCard(drawnCard)
                elif card.details == "draw4":
                    self.advanceTurn()
                    newColor = action[3]
                    self.piles[action[2]].topCard.color = newColor
                    for x in range(0,4):
                        drawnCard = self.deck.drawCard()
                        self.players[self.currentPlayerIndex].addCard(drawnCard)

                elif card.details == "wild":
                    newColor = action[3]
                    self.piles[action[2]].topCard.color = newColor
                    self.advanceTurn()
                elif card.details == "allDraw+-2":
                    self.allDrawRandom()
                    self.advanceTurn()
                elif card.details == "drawUntil":
                    newColor = action[3]
                    self.advanceTurn()
                    self.piles[action[2]].topCard.color = newColor
                    self.drawUntilColor(self.currentPlayerIndex, action[3])
                elif card.details == "swapHands":
                    swapHands(self.currentPlayerIndex, secondPlayerIndex)
                    self.advanceTurn()
                elif card.details == "swapDirection":
                    swapDirection = random.randint(0,2)
                    self.swapHandsDirection(swapDirection)
                    self.advanceTurn()
                elif card.details == "new-pile":
                    self.addPile(action[2])
                    self.advanceTurn()
                else:
                    pass
            else:
                pass

        def allDrawRandom(self):
                for x in self.players:
                        drawCards = 0
                        while(drawCards == 0):
                            drawCards = random.randint(-2,2)
                        if((x.getHandSize() + drawCards) <= 0):
                            x.clearHand()
                            for y in range(0,5):
                                card = self.deck.drawCard()
                                x.addCard(card)
                        elif(drawCards < 0):
                            for delCard in range(0, abs(drawCards)):
                                cardToDel = random.randint(0,x.getHandSize()-1)
                                x.removeCardIndex(cardToDel)

                        elif(drawCards > 0):
                            for j in range (0, drawCards):
                                card = self.deck.drawCard()
                                x.addCard(card)
                        else:
                            pass

        def drawTwo(self):
                for i in range(0,2):
                        drawnCard = self.deck.drawCard()
                        self.players[self.currentPlayerIndex].addCard(drawnCard)

def main():
        running = True
        # Do setup
        listOfPlayers = getPlayers()
        game = Game(listOfPlayers)
        # 3. give out hands and layout board

        while running:
                running = game.performAction(getPlayerAction(game.currentPlayer, game))
        # 4. start turn rotation
        #while running:
                #1.get input
                #2.update
                #3.draw to screen
        #       if keyboard.is_pressed('q'):
        #               running = False

def getPlayers():
        players =[]
        print("How many players?: ")
        numbPlayers = input()
        for x in range(int(numbPlayers)):

                print("Name of P"+str(x+1)+" ?: ")
                name = input()
                players.append(Player(name,x))
        return players

def getPlayerAction(player, game):
        print("Player: ", player.getName())
        print(player.getHand())
        print(game.getPiles())
        print("\t What Action do you choose?")
        print("\t\t 0. Draw a card :(")
        print("\t\t 1. Play a card :)")

        res_int = int(input())

        if res_int == 0:
                return [0]
        elif res_int == 1:
                print("What card do you want to play?")
                card_to_play = int(input())
                print("What pile do you want to play on?")
                pile_to_play = int(input())
                print("What color do you want to change to?:")
                color_to_change = int(input())
                return [1, card_to_play, pile_to_play, color_to_change]
        elif res_int == 2:
                return [2]
        else:
                return [-1]

#this just checks if the color and number are equal if so the card
#can be put on the pile
#NEEDS TO BE UPDATED TO INCLUDE SPECIAL CARDS
def checkCardCompatibility(pileCard, playerCard):
    if not playerCard.isSpecial:
        if playerCard.color == pileCard.color:
            return True
        elif playerCard.num == pileCard.num:
            return True
        else:
            return False
    elif playerCard.details == "draw2" or playerCard.details == "skip" or playerCard.details == "reverse" or playerCard.details == "allDraw+-2" or playerCard.details == "swapDirection":
        if playerCard.color == pileCard.color:
            return True
        elif playerCard.details == pileCard.details:
            return True
    else:
        if playerCard.details == "wild" or playerCard.details == "draw4" or playerCard.details == "drawUntil":
            return True
        elif playerCard.details == "new-pile":
            if pileCard is None:
                return True
            else:
                return playerCard.color == pileCard.color
        else:
            return playerCard.color == pileCard.color



if __name__ == '__main__':
        main()
