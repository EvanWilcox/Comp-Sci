import random

for num in range(1, 16):
    num1 = random.randint(1, 70)
    num2 = random.randint(1, 70)
    num3 = random.randint(1, 70)
    num4 = random.randint(1, 70)
    num5 = random.randint(1, 70)
    num6 = random.randint(1, 25)

    print "%-2s | %-2s %-2s %-2s %-2s %-2s %-2s" % \
    (num, num1, num2, num3, num4, num5, num6)