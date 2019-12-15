# Evan Wilcox
# CS 2200
# Homework 2
# Due: 2/7/19


# 1
def f(n):
    if n > 100:
        return n-10
    else:
        return f(f(n+11))

print "f(1) = ", f(1)
print "f(-6) = ", f(-6)
print "f(200) = ", f(200)
print "f(27) = ", f(27)

print "\n"

def g(n):
    if n - 10 < 91:
        return 91
    else:
        return n - 10

for i in range(0, 200):
    print f(i), g(i)



'''
#2
def A(x,y):
    A.counter += 1
    print "%s, A(%s, %s)" % (A.counter, x, y)
    if x == 0:
        return y+1
    elif y == 0:
        return A(x-1,1)
    else:
        return A(x-1,A(x,y-1))
A.counter = 0



for x in range(0, 5):
    for y in range(0, 5):
        print A(x, y)

'''