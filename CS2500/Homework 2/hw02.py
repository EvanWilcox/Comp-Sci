

import time
start_time = time.time()

def sum(n):
    sum = 0
    for i in range(n):
        print i, sum
        sum = sum + 2**i


n = 10
sum(32)



def binarySearch(v, A):
    if len(A) == 0:
        return -1
    
    l = 0
    m = len(A)/2
    h = len(A)
    while(l < m):
        if v < A[m]:
            h = m
        else:
            l = m
            
        m = (h+l)/2
    
    if A[m] != v:
        return -1

    return m


def selectionSort(A):
    for i in range(0, len(A)-1):
        min = i
        
        for j in range(i+1, len(A)):
            if A[j] < A[min]:
                min = j

        sw = A[i]
        A[i] = A[min]
        A[min] = sw

    return A


A = [10, 9, 4, 3, 2, 1, 8, 7, 6, 5]

for i in (A+[21, 22]):
    print i, binarySearch(i, A)

print selectionSort(A)
print(time.time() - start_time)

