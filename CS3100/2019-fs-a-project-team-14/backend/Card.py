'''
Card class defines a Card with a color and number
'''

class Card:
    # Constructor
    def __init__(self, color, num, isSpecial = False, details = None):
        self.color = color                  # String
        self.num = num                      # Int
        self.isSpecial = isSpecial          # Boolean
        self.details = details              # String
        
        '''
        Details for basic special cards
           * Skip    - "skip"
           * Reverse - "reverse"
           * Wild    - "wild"
           * Draw 2  - "draw2"
           * Draw 4  - "draw4"
        
        Skip, Reverse, and Draw 2 will have a color assigned at creation
        Wild and Draw 4 will have a color assigned when played
        
        Skip, Reverse, and Draw 2 should be created like:
            s = Card(color, None, True, "skip")
            r = Card(color, None, True, "reverse")
            d = Card(color, None, True, "draw2")
            
        Wild and Draw 4 should be created like:
            w = Card(None, None, True, "wild")
            d = Card(None, None, True, "draw4")
        '''
    def __str__(self):
        if not self.isSpecial:
            return str(self.color) + "-" + str(self.num)
        else:
            if self.details == "wild" or self.details == "draw4" or self.details == "drawUntil" or self.details == "new-pile":
                return self.details
            else:
                return str(self.color) + "-" + str(self.details)

    def __repr__(self):
        if not self.isSpecial:
            return str(self.color) + "-" + str(self.num)
        else:
            if self.details == "wild" or self.details == "draw4" or self.details == "drawUntil" or self.details == "new-pile":
                return self.details
            else:
                return str(self.color) + "-" + str(self.details)

    def __eq__(self, other):
        return ((self.color, self.num, self.details) == (other.color, other.num, other.details))

    def __ne__(self, other):
        return ((self.color, self.num, self.details) != (other.color, other.num, other.details))

    def __lt__(self, other):
        return ((self.color, self.num, self.details) < (other.color, other.num, other.details))

    def __le__(self, other):
        return ((self.color, self.num, self.details) <= (other.color, other.num, other.details))

    def __gt__(self, other):
        return ((self.color, self.num, self.details) > (other.color, other.num, other.details))

    def __ge__(self, other):
        return ((self.color, self.num, self.details) >= (other.color, other.num, other.details))



