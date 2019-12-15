

def bubble(A):
    for i in range(1, len(A)-1):
        for j in range(len(A)-1, i, -1):
            if A[j] < A[j-1]:
                print A
                swap = A[j]
                A[j] = A[j-1]
                A[j-1] = swap
    
    return A

L = [0, 5, 3, 1, 6, 4, 2]
print bubble(L)
