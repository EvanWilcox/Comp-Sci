'''
# @file   proj1.py
# @author Evan Wilcox, CS2500, Section 1A
# @brief  Short program used for experimentally testing merge sort and insertion 
#         sort's expected asymptotic complexity while testing the MergeSort and
#         InsertionSort class functionality.
''' 

from Sort import Sort
import time, random

sort = Sort()
sort.setDebug(False)

# Used for testing average-case run time.
# Sorts a random array of integers between 0 and n.
for x in [1, 10, 100, 1000, 10000, 100000, 1000000, 10000000]:
    for y in range(1, 10):
        n = x*y
        A = []
        for i in range(0, n):
            A.append(random.randint(0, n))
        
        B = A
        print("N = ", n)
        start = time.time()
        sort.MergeSort(A)
        print("Merge Sort     = ", time.time()-start)
        start = time.time()
        sort.InsertionSort(B)
        print("Insertion Sort = ", time.time()-start, "\n")
        
# Used for testing best-case run time.
# Sorts a sorted array of integers between 0 to n.
for x in [1, 10, 100, 1000, 10000, 100000, 1000000, 10000000]:
    for y in range(1, 10):
        n = x*y
        A = []
        for i in range(0, n):
            A.append(i)
        
        print("N = ", n)
        start = time.time()
        sort.MergeSort(A)
        print("Merge Sort     = ", time.time()-start)
        start = time.time()
        sort.InsertionSort(A)
        print("Insertion Sort = ", time.time()-start, "\n")
