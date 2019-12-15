#Evan Wilcox
#CS1200
#Homework 2
#Due: 2018-09-19, 11:59 PM

#3
def sum(n):
    if n <=1:
        return (n**3 + n)
    else:
        return (n**3 + n) + sum(n-1)

for n in range(1, 6):
    print sum(n)


#4
def f(n):
    if n <= 1:
        return n*(n+1)
    else:
        return n*(n+1) + f(n-1)

def g(n):
    return n*(n+1)*(n+2)/3


for n in range(1, 11):
    print 'n = %s, f(n) = %s, g(n) = %s' % (n, f(n), g(n))
