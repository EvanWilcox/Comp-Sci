from Card import Card

class Pile:

    def __init__(self):
        self.topCard = None
    # add card returns the top card after adding new one
    def addCard(self, card_to_add):
        old_top_card = self.topCard
        self.topCard = card_to_add
        return old_top_card

    def getTopCard(self):
        return self.topCard

    def __repr__(self):
        return str(self.topCard)
    def __str__(self):
        return str(self.topCard)

if __name__ == "__main__":
    pile1 = Pile()
    card1 = Card("R", 5)
    card2 = Card("B", 3)
    card3 = Card("Y", 3)
    print(pile1)
    print(pile1.getTopCard())
    print(pile1.addCard(card1))
    print(pile1.getTopCard())
    print(pile1.addCard(card2))
    print(pile1.getTopCard())
    print(pile1.addCard(card3))
    print(pile1.getTopCard())
