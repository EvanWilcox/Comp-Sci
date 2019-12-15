'''
# @file   InsertionSort.py
# @author Evan Wilcox, CS2500, Section 1A
# @brief  A class wrapper for Insertion Sort.
''' 

'''
# @class InsertionSort
# @brief A class wrapper for Insertion Sort.
''' 
class InsertionSort:
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
            assert type(val) == bool
        self.debug = val

    '''
    # @fn     sort
    # @brief  Sorts the given array using Insertion Sort.
    # @pre    A must be an array of integers.
    # @post   A is sorted.
    # @param  A an array containing integers.
    # @return A sorted array of integers.
    ''' 
    def sort(self, A):
        # Preconditions
        if self.debug:
            assert type(A) == list
            for i in range(len(A)):
                assert type(A[i]) == int
        '''
        # loop description
        # loop precondition:  loop’s precondition
        # loop postcondition: loop’s postcondition
        # invariant:          loop’s invariant
        # proof:              outline of initialization, maintenance, and termination
        ''' 
        for j in range(1, len(A)):
            # Invariant
            if self.debug:
                assert self.checkSort(A[0:j])
            
            key = A[j]
            i = j - 1
            
            '''
            # loop description
            # loop precondition:  loop’s precondition
            # loop postcondition: loop’s postcondition
            # invariant:          loop’s invariant
            # proof:              outline of initialization, maintenance, and termination
            ''' 
            while i >= 0 and A[i] > key:
                if self.debug:
                    assert self.checkSort(A[0:i])
                
                A[i + 1] = A[i]
                i = i - 1
            A[i + 1] = key
        
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
