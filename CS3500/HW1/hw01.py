# File: hw01.py
# Author: Evan Wilcox
# Class: CS3500
# Professor: Morales
# Date: 9/9/2019
# Description: Simple Lexical Analyser for Integers, Decimals, 
#              Scientific, Hexadecimal, Keywords, and Identifiers.

def integer(input):
    #GraphViz file: Integer.gv
    
    state = 0

    for i in input:
        if state == 0:
            if i == "+" or i == "-":
                state = 1
            elif i.isdigit():
                state = 2
            else:
                state = -1
        elif state == 1: 
            if i.isdigit():
                state = 2
            else:
                state = -1
        elif state == 2:
            if i.isdigit():
                state = 2
            else:
                state = -1
        else:
            state = -1

    return state == 2


def decimal(input):
    # GraphViz File: Decimal.gv

    state = 0
    index = input.find(".")
    
    if index > -1:
        if integer(input[:index]):
            state = 1
        else:
            state = -1
    else:
        state = -1
    
    for i in input[index:]:
        if state == 1:
            if i == ".":
                state = 2
            else:
                state = -1
        elif state == 2:
            if i.isdigit():
                state = 3
            else:
                state = -1
        elif state == 3:
            if i.isdigit():
                state = 3
            else:
                state = -1
        else:
            state = -1

    return state == 3


def scientific(input):
    # GraphViz File: Scientific.gv

    state = 0
    index = input.find("E")
    
    if index > -1:
        if decimal(input[:index]):
            state = 1
        else:
            state = -1
    else:
        state = -1
    
    for i in input[index:]:
        if state == 1:
            if i == "E":
                state = 2
            else:
                state = -1
        elif state == 2:
            if i == "-" or i == "+":
                state = 3
            elif i.isdigit() and i != "0":
                state = 4
            else:
                state = -1
        elif state == 3:
            if i.isdigit() and i != "0":
                state = 4
            else:
                state = -1
        elif state == 4:
            if i.isdigit():
                state = 4
            else:
                state = -1
        else:
            state = -1

    return state == 4


def hexadecimal(input):
    # GraphViz File: Hexadecimal.gv

    state = 0

    for i in input:
        if state == 0:
            if i.isdigit() or i in hex:
                state = 0
            elif i == "H":
                state = 1
            else:
                state = -1
        else:
            state = -1

    return state == 1


def keyword(input):
    return (input in keywords)


def identifier(input):
    # GraphViz File: Identifier.gv
    
    state = 0

    for i in input:
        if state == 0:
            if i.isalpha():
                state = 1
            else:
                state = -1
        elif state == 1:
            if i.isalpha() or i.isdigit() or i == "-":
                state = 1
            else:
                state = -1
        else:
            state = -1

    return state == 1


def phoneNumber(input):
    # GraphViz File: Phone.gv

    state = 0
    
    for i in input:
        if state == 0:
            if i.isdigit():
                state = 1
            elif i == "(":
                state = 12
            else:
                state = -1
        elif state == 1:
            if i.isdigit():
                state = 2
            else:
                state = -1
        elif state == 2:
            if i.isdigit():
                state = 3
            else:
                state = -1
        elif state == 3:
            if i == ".":
                state = 4
            elif i == "-":
                state = 5
            else:
                state = -1
        elif state == 4:
            if i.isdigit():
                state = 6
            else:
                state = -1
        elif state == 5:
            if i.isdigit():
                state = 9
            else:
                state = -1
        elif state == 6:
            if i.isdigit():
                state = 7
            else:
                state = -1
        elif state == 7:
            if i.isdigit():
                state = 8
            else:
                state = -1
        elif state == 8:
            if i == ".":
                state = 17
            else:
                state = -1
        elif state == 9:
            if i.isdigit():
                state = 10
            else:
                state = -1
        elif state == 10:
            if i.isdigit():
                state = 11
            else:
                state = -1
        elif state == 11:
            if i == "-":
                state = 18
            else:
                state = -1
        elif state == 12:
            if i.isdigit():
                state = 13
            else:
                state = -1
        elif state == 13:
            if i.isdigit():
                state = 14
            else:
                state = -1
        elif state == 14:
            if i.isdigit():
                state = 15
            else:
                state = -1
        elif state == 15:
            if i == ")":
                state = 16
            else:
                state = -1
        elif state == 16:
            if i.isdigit():
                state = 9
            else:
                state = -1
        elif state == 17:
            if i.isdigit():
                state = 19
            else:
                state = -1
        elif state == 18:
            if i.isdigit():
                state = 19
            else:
                state = -1
        elif state == 19:
            if i.isdigit():
                state = 20
            else:
                state = -1
        elif state == 20:
            if i.isdigit():
                state = 21
            else:
                state = -1
        elif state == 21:
            if i.isdigit():
                state = 22
            else:
                state = -1
        elif state == 22:
            state = -1
        else:
            state = -1
    
    return state == 22
    


# Additional Hex Characters
hex = ["A", "B", "C", "D", "E", "F"]

# Required Keywords
keywords = ["WHILE", "ELSE", "IF", "END"]

# Get count of iterms to read
count = int(input())

for i in range(count):
    line = input()
    # Remove '\n' character
    line = line[:-1]
    
    output = str(i+1) + ": "

    if integer(line):
        output += "Integer."
    
    elif decimal(line):
        output += "Decimal."

    elif scientific(line):
        output += "Scientific."

    elif keyword(line):             # Keyword before Identifier
        output += "Keyword."        

    elif hexadecimal(line):         # Hexadecimal before Identifier
        output += "Hexadecimal."    

    elif identifier(line):
        output += "Identifier."   

    elif phoneNumber(line):
        output += "Phone."
    
    else:
        output += "INVALID!"

    print(output)
