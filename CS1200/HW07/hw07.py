# Evan Wilcox
# CS1200 Fall 2018
# Homework 7
# Due: Monday 12/05/18 11:59pm

#8
def C(n, k):
    if (k == 0 or k == n):
        return 1
    else: 
        return C(n-1, k-1) + C(n-1, k)

print "C(13,5) =", C(13, 5)