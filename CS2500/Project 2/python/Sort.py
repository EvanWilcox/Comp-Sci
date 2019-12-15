'''
# @file   Sort.py
# @author Evan Wilcox, CS2500, Section 1A
# @brief  A wrapper class for Merge Sort, Heap Sort and Quick Sort.
''' 

'''
# @class Sort
# @brief A class wrapper for Merge Sort and Insertion Sort.
''' 
class Sort:
    '''
    # @fn    __init__
    # @brief Class initializer.
    # @pre   No pre-condition.
    # @post  A Sort object is created.
    ''' 
    def __init__(self):
        self.debug = False      # indicates whether debug mode is enabled.
    

    '''
    # @fn    setDebug
    # @brief Sets the debug mode on or off.
    # @pre   val must be a boolean
    # @post  The new debug mode is set.
    # @param val new intended debug mode
    ''' 
    def setDebug(self, val):
        # Precondition
        if self.debug:
            assert type(val) == bool
        
        self.debug = val
    
    '''
    # @fn     MergeSort
    # @brief  Sorts the given array using Merge Sort.
    # @pre    A must be an array of integers.
    # @post   A is sorted.
    # @param  A an array containing integers.
    # @return A sorted array of integers.
    '''
    def MergeSort(self, A):
        # Precondition
        if self.debug:
            assert type(A) == list
            for i in range(len(A)):
                assert type(A[i]) == int
        
        if len(A) <= 1:
            return A
        else:
            m = len(A)//2
            L = self.MergeSort(A[:m])
            R = self.MergeSort(A[m:])
            
            # Postcondition
            if self.debug:
                assert self.checkSort(self.merge(L, R))
            
            return self.merge(L, R)

    '''
    # @fn     merge
    # @brief  Merges two sorted arrays in to one sorted array.
    # @pre    Both L and R must be arrays of integers in sorted order.
    # @post   L and R are merged in to one sorted array.
    # @param  L An array of sorted integers.
    # @param  R An array of sorted integers.
    # @return An array of sorted integers.
    ''' 
    def merge(self, L, R):
        # Preconditions
        if self.debug:
            assert type(L) == list
            assert type(R) == list
            
            for i in range(len(L)):
                assert type(L[i]) == int
                
            for i in range(len(R)):
                assert type(R[i]) == int
        
            assert self.checkSort(L)
            assert self.checkSort(R)

        S = []
        '''
        # loop description while loop that merges two arrays 
        # invariant:       S consists of elements from L and R in sorted order
        # proof:           
        # initialization:
        #    S is initialized to [] so it is sorted.
        #
        # maintenance: 
        #   The first element is removed from L or R and added to
        #   S. Because L and R are sorted S stays sorted.
        #
        # termination:
        #   Because an element is always removed from L or R either
        #   L or R size will equal 0 so the while loop will terminate.
        ''' 
        while len(L) > 0 and len(R) > 0:
            # Invariant
            if self.debug:
                assert self.checkSort(S)
            
            if L[0] < R[0]:
                S.append(L[0])
                L = L[1:]
            else:
                S.append(R[0])
                R = R[1:]
        
        if len(L) == 0:
            S = S + R
        elif len(R) == 0:
            S = S + L
        
        # Postcondition
        if self.debug:
            assert self.checkSort(S)
        
        return S


    def HeapSort(self, A):
        # Preconditions
        if self.debug:
            assert type(A) == list
            for i in range(len(A)):
                assert type(A[i]) == int
        
        heapSize = len(A)

        for i in range(heapSize//2, -1, -1):
            self.heapify(A, heapSize, i)
        
        for i in range(heapSize-1, 0, -1):
            A[i], A[0] = A[0], A[i]
            self.heapify(A, i, 0)
        
        # Postcondition
        if self.debug:
            assert self.checkSort(A)
        
        return A


    def heapify(self, A, heapSize, i):
        # Preconditions
        if self.debug:
            assert type(A) == list
            for j in range(len(A)):
                assert type(A[j]) == int

            assert type(heapSize) == int
            assert type(i) == int
        
        
        largest = i
        l = (2 * i) + 1    
        r = (2 * i) + 2

        if l < heapSize and A[l] > A[i]:
            largest = l
        if r < heapSize and A[r] > A[largest]:
            largest = r
        if largest != i:
            A[i], A[largest] = A[largest], A[i]
            self.heapify(A, heapSize, largest)

            # Postcondition
            if self.debug:
                assert self.checkHeap(A, heapSize, largest)


    def QuickSort(self, A):

        if len(A) == 0:
            return []
        else:
            p = self.partition(A)
            return self.QuickSort(A[:p]) + [A[p]] + self.QuickSort(A[p+1:])

    
    def partition(self, A): 
        low = 0
        high = len(A) - 1
        
        x = A[high]
        i = low-1
    
        for j in range(low, high): 
            if A[j] <= x: 
                i = i+1 
                A[i],A[j] = A[j],A[i] 
    
        A[i+1],A[high] = A[high],A[i+1] 
        return i+1
    

    '''
    # @fn     checkSort
    # @brief  Checks if the given array A is in sorted order.
    # @pre    A must be an array on integers.
    # @post   A boolean is returned.
    # @param  A an array of integers.
    # @return Boolean indicating if the passed array is sorted in 
              increasing order.
    ''' 
    def checkSort(self, A):
        # Preconditions
        if self.debug:
            assert type(A) == list
            for i in range(len(A)):
                assert type(A[i]) == int
        
        for i in range(len(A)-1):
            if A[i] > A[i+1]:
                return False

        return True


    def checkHeap(self, A, heapSize, i):
        # Preconditions
        if self.debug:
            assert type(A) == list
            assert type(heapSize) == int
            for j in range(len(A)):
                assert type(A[j]) == int

        
        if (i * 2 + 1) < heapSize:
            if A[i * 2 + 1] > A[i]:
                return False
        
        if (i * 2 + 2) < heapSize:
            if A[i * 2 + 2] > A[i]:
                return False
        
        return True
