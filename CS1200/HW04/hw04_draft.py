#Evan Wilcox
#CS1200 Fall 2018
#Homework 4
#Due: 2018-10-22, 11:59 PM


#2a
def h1(P, Q):
    return P <= (not Q)

def h2(R, Q):
    return (not R) or Q

def h3(R):
    return R

def con(P):
    return not P

print "|   P   |   Q   |   R   | P->~Q | ~R|Q  |   R   |  ~P   |"
print "========================================================="
for P in [False, True]:
    for Q in [False, True]:
        for R in [False, True]:
            print "| %-5s | %-5s | %-5s | %-5s | %-5s | %-5s | %-5s |" \
            % (P, Q, R, h1(P, Q), h2(R, Q), h3(R), con(P))


#2b
def h1(P, Q):
    return P <= Q

def h2(Q, R):
    return Q <= R

def con(P, R):
    return P <= R

print "|   P   |   Q   |   R   | P->Q  | Q->R  | P->R  |"
print "================================================="
for P in [False, True]:
    for Q in [False, True]:
        for R in [False, True]:
            print "| %-5s | %-5s | %-5s | %-5s | %-5s | %-5s |" \
            % (P, Q, R, h1(P, Q), h2(Q, R), con(P, R))



'''
#4a
def h1(P, Q):
    return P <= Q

def h2(Q):
    return not Q

def con(P):
    return P

print "|   P   |   Q   | P->Q  |  ~Q   | ~(~P) |"
print "========================================="
for P in [False, True]:
    for Q in [False, True]:
        for R in [False, True]:
            print "| %-5s | %-5s | %-5s | %-5s | %-5s |" \
            % (P, Q, h1(P, Q), h2(Q), con(P))




#4b
def h1(P, Q):
    return P <= (not Q)

def h2(Q, R):
    return Q  or R

def h3(P):
    return P

def con(R):
    return not R

print "|   P   |   Q   |   R   | P->~Q |  Q|R  |   P   |  ~R   |"
print "========================================================="
for P in [False, True]:
    for Q in [False, True]:
        for R in [False, True]:
            print "| %-5s | %-5s | %-5s | %-5s | %-5s | %-5s | %-5s |" \
            % (P, Q, R, h1(P, Q), h2(Q, R), h3(P), con(R))
'''



'''
#5
def h1(M, C, S, H):
    return (M and C) <= ((not S) or H)

def h2(M, C, S, H):
    return ((not C) or S) <= ((not M) and (not H))

def h3(M, C, S, H):
    return ((not M)  <= C) or ((not S) <= H)

def con(M, C, S, H):
    return not ((M or S) <= (C and (not H)))

print "|   M   |   C   |   S   |   H   |   h1  |   h2  |   h3  |  con  |"
print "================================================================="
for M in [False, True]:
    for C in [False, True]:
        for S in [False, True]:
            for H in [False, True]:
                if h1(M, C, S, H) and h2(M, C, S, H) and h3(M, C, S, H) and con(M, C, S, H):
                    print "| %-5s | %-5s | %-5s | %-5s | %-5s | %-5s | %-5s | %-5s |" \
                    % (M, C, S, H, h1(M, C, S, H), h2(M, C, S, H), h3(M, C, S, H), con(M, C, S, H))
'''




#6
people = ["Clark", "Daw", "Fuller"]
def distinct(L):
    if len(L) < 2:
        return True
    else:
        j = L.pop()
    if j in L:
        return False
    return distinct(L)

def workedFor(p1, p2):
    global carpenter, painter, plumber
    if (p1 == painter) and (p2 == carpenter):
        return True
    if (p1 == carpenter) and (p2 == plumber):
        return True
    return False

def notHeardOf(p1, p2):
    return (p1 == "Fuller") and (p2 == "Daw")

def earnsMore(p1, p2):
    global carpenter, painter, plumber
    if p1 == p2:
        return False
    if p2 == plumber:
        return False
    if p2 == "Daw":
        return False
    return True

def solve():
    global carpenter, painter, plumber
    for carpenter in people:
        for painter in people:
            for plumber in people:
                if distinct([carpenter, painter, plumber]):
                    sol = workedFor(painter, carpenter)
                    sol = sol and workedFor(carpenter,plumber)
                    sol = sol and earnsMore(plumber,painter)
                    sol = sol and notHeardOf(painter, plumber)
                    if sol:
                        print "Carpenter = %s, Painter = %s, Plumber = %s" \
                        % (carpenter, painter, plumber)

solve()


#7
A = 100
for B in range(-100, 101):
    if (A==-B) | (A > B):
        print A, B, "True"
    else:
        print A, B, "False"

