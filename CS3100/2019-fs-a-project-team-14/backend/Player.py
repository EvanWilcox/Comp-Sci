import Card
class Player:
    # Constructor
    def __init__(self, name, PlayerID):
        self.name = name
        self.PlayerID = PlayerID
        self.hand = []

    def getHand(self):
        return self.hand

    def getName(self):
        return self.name

    def getHandSize(self):
        return len(self.hand)

    #deletes all cards in the players hand
    def clearHand(self):
        self.hand.clear()

    # inserts drawn card object in correctly sorted position to hand array
    def addCard(self,card):
                added = False
                foundColor = False;
                if not card.isSpecial:
                    for i in range(0, len(self.hand)):
                        if not self.hand[i].isSpecial and not foundColor and not added:
                                if card < self.hand[i]:
                                        self.hand.insert(i,card)
                                        added = True
                        elif self.hand[i].isSpecial and (self.hand[i].color == card.color) and not added:
                            self.hand.insert(i,card)
                            added = True
                        elif(self.hand[i].details == "wild" or self.hand[i].details == "draw4"
                             or self.hand[i].details == "drawUntil" or self.hand[i].details == "new-pile") and not added:
                           self.hand.insert(i, card)
                           added = True
                        elif self.hand[i].color == card.color and not added:
                            self.hand.insert(i, card)
                            added = True



                else:
                    for j in range(0, len(self.hand)):
                        if(self.hand[j].details == "wild" or self.hand[j].details == "draw4"
                             or self.hand[j].details == "drawUntil" or self.hand[j].details == "new-pile") and not added:
                           self.hand.insert(j, card)
                           added = True
                        elif foundColor == True and not added:
                                if self.hand[j].color != card.color:
                                        self.hand.insert(j, card)
                                        added = True
                        elif self.hand[j].color == card.color and not added:
                                foundColor = True



                if not added:
                        self.hand.append(card)

    def removeCardIndex(self, cardindex):
        card = self.hand[cardindex]
        del self.hand[cardindex]
        return card

    def removeCard(self, card):
        self.hand.remove(card)
        return card



    # overloaded print function
    def print(self):
        print(self.name, self.PlayerID)

    def __lt__(self, them):
        return self.PlayerID < them.PlayerID

    def __str__(self):
        retAns = ("<" + str(self.name) + " " + str(self.PlayerID) + "; ")
        for card in self.hand:
            retAns += str(card)
            retAns += ", "
        retAns = retAns[:-2]
        retAns += ">"
        return retAns

    def __repr__(self):
        retAns = ("<" + str(self.name) + " " + str(self.PlayerID) + "; ")
        for card in self.hand:
            retAns += str(card)
            retAns += ", "
        retAns = retAns[:-2]
        retAns += ">"
        return retAns
