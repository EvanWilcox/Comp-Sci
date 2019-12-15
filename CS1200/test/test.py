def repeat(L):
    if len(L) == 0:
        return []
    else:
        #return L[:1] + L[:1] + repeat(L[1:])
        return [L[0] , L[0]] + repeat(L[1:])

myList = [1, 2, 3, 4, 5]
print repeat(myList)