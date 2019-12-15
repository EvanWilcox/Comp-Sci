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
