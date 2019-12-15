'''
# @file   Sort.py
# @author Evan Wilcox, CS2500, Section 1A
# @brief  A class wrapper for Merge Sort and Insertion Sort.
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
            m = int(len(A)/2)
            L = self.MergeSort(A[0:m])
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


    '''
    # @fn     InsertionSort
    # @brief  Sorts the given array using Insertion Sort.
    # @pre    A must be an array of integers.
    # @post   A is sorted.
    # @param  A an array containing integers.
    # @return A sorted array of integers.
    ''' 
    def InsertionSort(self, A):
        # Preconditions
        if self.debug:
            assert type(A) == list
            for i in range(len(A)):
                assert type(A[i]) == int
        '''
        # loop description iterates through elements in the array
        # invariant:       A[1..j-1] consists of elements originally in A[1..j-1]
        #                  but in sorted order.
        # proof:           
        # initialization:
        #    Before the loop j=2 so the subarray A[1..j-1] contains 1 element. 
        #
        # maintenance: 
        #   The while loop moves A[j] around until it is in sorted order. j is incremented
        #   so the subarray A[1..j] is in sorted order.
        #
        # termination:
        #   The terminating condition is j > A.length, at this time j = A.length + 1. 
        #   Subsitute that in to the invariant and the subarry A[1..A.length] contains
        #   elements originally from A[1..A.length] but in sorted order.
        ''' 
        for j in range(1, len(A)):
            # Invariant
            if self.debug:
                assert self.checkSort(A[0:j])
            
            key = A[j]
            i = j - 1

            while i >= 0 and A[i] > key:
                if self.debug:
                    assert self.checkSort(A[0:i])
                
                A[i + 1] = A[i]
                i = i - 1
            A[i + 1] = key
        
        # Postcondition
        if self.debug:
            assert self.checkSort(A)
        
        return A


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
        
        for i in range(0, len(A)-1):
            if A[i] > A[i+1]:
                return False

        return True
