'''
# @file   MergeSort.py
# @author Evan Wilcox, CS2500, Section 1A
# @brief  A class wrapper for Merge Sort.
''' 

'''
# @class MergeSort
# @brief A class wrapper for Merge Sort.
''' 
class MergeSort:
    '''
    # @fn    __init__
    # @brief Class initializer.
    # @pre   No pre-condition.
    # @post  A InsertionSort object is created.
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
            type(val) == bool
        
        self.debug = val
    
    '''
    # @fn     sort
    # @brief  Sorts the given array using Merge Sort.
    # @pre    A must be an array of integers.
    # @post   A is sorted.
    # @param  A an array containing integers.
    # @return A sorted array of integers.
    '''
    def sort(self, A):
        # Precondition
        if self.debug:
            assert type(A) == list
            for i in range(len(A)):
                assert type(A[i]) == int
        
        if len(A) <= 1:
            return A
        else:
            m = int(len(A)/2)
            L = self.sort(A[0:m])
            R = self.sort(A[m:])
            
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
        # loop description
        # loop precondition:  loop’s precondition
        # loop postcondition: loop’s postcondition
        # invariant:          loop’s invariant
        # proof:              outline of initialization, maintenance, and termination
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
