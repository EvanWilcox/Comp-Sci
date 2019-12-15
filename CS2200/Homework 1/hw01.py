# CS2200 
# Homework 1
# Evan Wilcox
# Due: 2019/01/29 11:59 PM

import math

#6b
def fib(n):
    if n <= 1:
        return 1
    else:
        return fib(n-1) + fib(n-2)

def fibEncode(n):
    if n < 1:
        return "n not positive!"
    Fib = [0,1]
    while Fib[-1] <= n:
        Fib += [Fib[-1] + Fib[-2]]
    Fib = Fib[:-1]
    rep = '1'
    for i in range(len(Fib)-1,1,-1):
        if Fib[i] <= n:
            rep = '1'+rep
            n = n - Fib[i]
        else:
            rep = '0' + rep
    return rep

phi = (1 + math.sqrt(5))/2

print "|  Start  |   End   | Num Digits | Log2(Start)+2 | LogPhi(Start)+2 |"
print "--------------------------------------------------------------------"

for i in range(1,31):
    
    start = fib(i)
    end = fib(i+1) - 1
    numDigits = len(fibEncode(start))
    
    print "| %7d | %7d | %10d | %11d.0 | %13d.0 |" % \
    (start, end, numDigits, math.log(start, 2) + 2.0, math.log(start, phi) + 2.0)




for i in range(0, 100):
    print i, fibEncode(i)