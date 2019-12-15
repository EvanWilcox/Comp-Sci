# File: pdaSim.py
# Author: Evan Wilcox
# Class: CS2200, Markowsky
# Due: 4/16/19, 11:59 PM

#3 
def pdaSim(file):
    f = open(file, "r")

    states = []
    delta = []
    outputs = []
    l = []
    stack = []
    
    for line in f:
        l.append(line)
        
        if line[0] == 'A':
            alphabet = line[2:]

        if line[0] == 'K':
            stackAlphabet = line[2:]
            
        if line[0] == 'S':
            states.append([line[2:len(line)-4], int(line[len(line)-2:len(line)-1])])

        if line[0] == 'B':
            beginState = line[2:-1]

        if line[0] == 'D':
            startState = line[2:line.index(',')]
            tape = line[line.index(',')+2:line.index(',', line.index(',')+1)]
            stack = line[line.index(tape)+len(tape)+2:line.index(',', line.index(tape)+2)]
            replace = line[line.index(stack)+len(stack)+2:line.index(',', line.index(stack)+2)]
            endState = line[line.index(replace)+len(replace)+2:-1]

            delta.append([startState, tape, stack, replace, endState])
        
        if line[0] == 'T':
            tape = line[2:-1]
            state = beginState
            
            for t in tape:
                for d in delta:
                    if state == d[0] and d == d[1]:
                        if d[2] != '@' and d[2] == stack[len(stack)-1] and d[1] == t:
                            state = d[4]

                            if d[2] == '@' and d[3] != '@':
                                stack.append(d[3])
                            
                            elif d[2] != '@' and d[3] == '@':
                                stack.pop()
                            break
            
            if [state, 1] in states:
                outputs.append("Accepted")
            else: 
                outputs.append("Rejected")


    f.close()

    w = open(file, 'w')
    for line in l:
        if line[0] == 'O':
            line = line[:2] + outputs[0] + line[-1:]
            outputs = outputs[1:]

        w.write(line)
    
    w.close()



pdaSim("4a.fsa")