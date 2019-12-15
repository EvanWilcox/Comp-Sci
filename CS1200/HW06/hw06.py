# Evan Wilcox
# CS1200 Fall 2018
# Homework 6
# Due: Monday 11/26/18 11:59pm

#3b
A = [0, 1, 2, 3, 4]
R = [(0, 0),(0, 4),(1, 1),(1, 3),(2, 2),(3, 1),(3, 3),(4, 0),(4, 4)]

def Reflexive(D,R):
    for x in D:
        if (x,x) not in R:
            return False
    return True

def Symmetric(R):
    for (a,b) in R:
        if (b,a) not in R:
            return False
    return True

def AntiSymmetric(R):
    for (a,b) in R:
        if (a !=b) and ((b,a) in R):
            return False
    return True

def Transitive(R):
    for (a,b) in R:
        for (c,d) in R:
            if (b == c) and ((a,d) not in R):
                return False 
    return True

def PartialOrder(D, R):
    return Reflexive(D,R) and AntiSymmetric(R) and Transitive(R)

def TotalOrder(D, R):
    for a in D:
        for b in D:
            if (a, b) not in R and (b, a) not in R:
                return False
    return True

def WellOrder(R):
    for (a, b) in R:
        if not (a <= b):
            return False
    return True

def EquivalenceRel(D, R):
    return Reflexive(D,R) and Symmetric(R) and Transitive(R)

print "-----#3b-----"
print "R =", R
print "Reflexive =", Reflexive(A,R)
print "Symmetric =", Symmetric(R)
print "AntiSymmetric =", AntiSymmetric(R)
print "Transitive =", Transitive(R)
print "Partial Order =", PartialOrder(A, R)
print "Total Order =", TotalOrder(A, R)
print "Well Order =", WellOrder(R)
print "Equivalence Relation =", EquivalenceRel(A, R)




#4
def matrix():
    m = []
    for a in range(1, 21):
        m.append([])
        for b in range(1, 21):
            m[a-1].append([])
            m[a-1][b-1] = int((a-b) % 4 == 0)

    for i in range(0, 20):
        print m[i]
    
    R = []
    for a in range(1, 21):
        for b in range(1, 21):
            if m[a-1][b-1]:
                R.append((a,b))
    
    return R

R = matrix()
A = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 17, 19, 20]

print "-----#4-----"
print R
print "Equivalence Relation =", EquivalenceRel(A, R)
print "Partial Order =", PartialOrder(A, R)
print "Total Order =", TotalOrder(A, R)
print "Well Order =", WellOrder(R)





#5
A = [0, 1, 2, 3, 4, 5]
R = [(0, 5), (1, 3), (2, 0), (3, 0), (4, 4), (5, 1)]

def Injection(R):
    Bs = []
    for (a, b) in R:
        Bs.append(b)
    
    for x in Bs:
        if Bs.count(x) > 1:
            return False
    
    return True

def Surjection(A, R):
    Bs = []
    for (a, b) in R:
        Bs.append(b)

    for x in A:
        if x not in Bs:
            return False

    return True

def Bijection(A, R):
    return (Injection(R) and Surjection(A, R))

print "-----#5-----"
print "Injection =", Injection(R)
print "Surjection =", Surjection(A, R)
print "Bijection =", Bijection(A, R)

