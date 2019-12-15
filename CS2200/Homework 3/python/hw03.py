# Evan Wilcox
# Comp Sci 2200
# Homework 3
# Due: 2/26/19, 11:59

from simulator import Simulator

# 1a
def Merge(L, R):
    if len(L) == 0:
        return R
    elif len(R) == 0:
        return L
    elif L[0] < R[0]:
        return L[:1] + Merge(L[1:], R)
    else:
        return R[:1] + Merge(L, R[1:])

# 1b
def MergeSort(A):
    if len(A) <= 1:
        return A
    else:
        m = len(A)/2
        return Merge(MergeSort(A[:m]), MergeSort(A[m:]))

L = [9, 6, 5, 3, 6, 9, 7, 5, 8, 0, 7, 2, 1, 8, 4, 4, 3, 2, 1, 0]
print(MergeSort(L))


# 3
s = Simulator("q4.fsa")
s = Simulator("q5.fsa")


