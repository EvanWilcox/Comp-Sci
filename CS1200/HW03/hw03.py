#Evan Wilcox
#CS1200
#Homework 3
#Due: 2018-10-05, 11:59 PM

#2
def ls(P, Q):
    return not (P or Q)

def rs(P, Q):
    return (not P) and (not Q)

print "|   P   |   Q   |~(P|Q) | ~P&~Q |"
print "----------------------------------"
for p in [False, True]:
    for q in [False, True]:
        print "| %-5s | %-5s | %-5s | %-5s |" \
        % (p, q, ls(p, q), rs(p, q))
