import random
from Card import Card
class Deck:

    cards = []

    #Constructor for Class Deck. Makes 2 of each color for 1-9, one of each color with value 0
    def __init__(self):
        for i in range(0,2):
            for c in ["red","yellow","green","blue"]:
                for v in range(1,10):
                    self.cards.append(Card(c,v))

        for i in range(0,1):
            for c in ["red","yellow","green","blue"]:
                self.cards.append(Card(c,0))

        #creates p speical cards skip, reverse, and draw (all of these should have a color)
        for w in ["red", "yellow", "green", "blue"]:
            for m in ["skip", "reverse", "draw2", "allDraw+-2", "swapDirection"]:
                for p in range(0, 2):
                    self.cards.append(Card(w, None, True, m))

        #creates 4 each of wild and draw4 cards
        for l in range(0, 4):
            for o in ["wild", "draw4", "drawUntil"]:
                self.cards.append(Card(None, None, True, o))


        for i in range(3):
            self.cards.append(Card(None, None, True, "new-pile"))

    #use shuffle() provided by random library to shuffle array deck
    def shuffle(self):
        random.shuffle(self.cards)

    #returns first Card object of array Deck and "refills" deck once array is emptied
    def drawCard(self):
        try:
            return self.cards.pop()
        except:
            for i in range(0,2):
                for c in ["red","yellow","green","blue"]:
                    for v in range(1,10):
                        self.cards.append(Card(c,v))

            for i in range(0,1):
                for c in ["red","yellow","green","blue"]:
                    self.cards.append(Card(c,0))

            #creates p speical cards skip, reverse, and draw (all of these should have a color)
            for w in ["red", "yellow", "green", "blue"]:
                for m in ["skip", "reverse", "draw2", "allDraw+-2", "swapDirection"]:
                    for p in range(0, 2):
                        self.cards.append(Card(w, None, True, m))

            #creates 4 each of wild and draw4 cards
            for l in range(0, 4):
                for o in ["wild", "draw4", "drawUntil",]:
                    self.cards.append(Card(None, None, True, o))

            random.shuffle(self.cards)
            return self.cards.pop()

    # returns string of the contents of the deck
    def __str__(self): #print all cards in deck
        toString = "======= Contents of deck: =======\n"
        for c in self.cards:
            toString += str(c)
            toString += '\n'
        toString += "================================="
        return toString
