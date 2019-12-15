#Evan Wilcox
#CS1200
#Homework 1
#Due: 2018-09-04, 11:59 PM


#1a
word = "foobar"
print word[-2]
print word[2]
print word[0:2]
print word[:2]
print word[::2]
print word[::-1]


#1b
def numLegs(n):
    if n == 0:
        print("haha you can not walk!")
    if n == 1:
        print("you hop!")
    if n == 2:
        print("that is normal")
    else:
        print("you must trip yourself")

numLegs(1)


#1c
for s in ["b", "c"]:
    for n in [1, 4]:
        print s*n,


#1d
a = [1, 2]
b = []
b.append(a)
b.append(a)
a.append(3)
print b


#1e
for i in range(2, 11):
    print "1/%s = %.3f" % (i, 1.0/i)


#2a
def fermatCheck(a, b, c, n):
    if ((a**n + b**n) == c**n) and n > 2:
        print "Fermat was wrong!"
    else:
        print "That doesn't work"

fermatCheck(3987, 4365, 4472, 12)


#3
def altDif(nums):
    if len(nums) <= 1:
        return nums[0]
    else:
        return nums[0] - altDif(nums[1:])


myNums1 = [7, 6, 9, 10]
myNums2 = [3, 5, 4]
myNums3 = [6, 7]

print altDif(myNums1)
print altDif(myNums2)
print altDif(myNums3)


#4
def f(x):
    if x > 100:
        return x - 9
    else:
        return f(f(x+10))


#4a
print f(0)
print f(-9)
print f(45)
print f(99)
print f(100)
print f(250)


#4b
def g(x):
    if x <= 100:
        return 92
    else:
        return x - 9

print g(0)
print g(-9)
print g(45)
print g(99)
print g(100)
print g(250)


#5
def SuperReverse(l):
    if len(l) <= 1:
       return l
    else:
        return SuperReverse(l[-1:]) + SuperReverse(l[:-1])

mylist = [[1,9], [5, [6, 2]], 3]
print mylist
print SuperReverse(mylist)


#6
def Q(x,y):
    if x == 0:
        return y+1
    if y == 0:
        return Q(x-1,1)
    else:
        return Q(x-1,Q(x,y-1))


#6a
for x in range(0, 4):
    for y in range(0, 6):
        print "Q(%s,%s) = %s" % (x, y, Q(x, y))


#6b
#For Q(2,2), Q called 27 times
