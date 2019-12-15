

import math

def factorial(n):
    sum = 1
    for i in range(1, n+1):
        sum = sum * i
    
    return sum


target = 1000000 * 60 * 60 * 24 * 30 * 12 * 100
n = 0

print 2**1000000


print IntToStr(math.log(target, 2))