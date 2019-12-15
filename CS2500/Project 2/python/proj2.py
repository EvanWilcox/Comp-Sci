from Sort import Sort
import time, random, sys

sys.setrecursionlimit(10000)

S = Sort()
S.setDebug(False)

'''
T = [23, 17, 14, 6, 13, 10, 1, 5, 7, 12]
for i in range(len(T)):
    print( S.checkHeap(T, len(T), i))
'''


A = B = C = []
n = 10000
for i in range(0, n):
    rint = random.randint(0, n*10)
    A.append(rint)
    B.append(rint)
    C.append(rint)


start = time.time()
S.MergeSort(A)
print("MergeSort:", time.time()-start)

start = time.time()
S.HeapSort(B)
print("HeapSort:", time.time()-start)

start = time.time()
S.QuickSort(C)
print("QuickSort:", time.time()-start)
'''

A = [6, 9, 2, 7, 10, 5, 1, 3, 8, 4]
print(S.QuickSort(A))
'''