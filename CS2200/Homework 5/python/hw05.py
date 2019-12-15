# Evan Wilcox
# Comp Sci 2200
# Homework 4
# Due: 3/19/19, 11:59



# 1
# NDFSA+e Simulator
class Simulator():
    def __init__(self, file):
        f = open(file, "r")

        self.states = []
        self.delta = []
        outputs = []
        l = []
        
        for line in f:
            l.append(line)
            
            if line[0] == 'A':
                self.alphabet = line[2:]
                
            if line[0] == 'S':
                self.states.append([line[2:len(line)-4], int(line[len(line)-2:len(line)-1])])

            if line[0] == 'B':
                self.beginState = line[2:-1]

            if line[0] == 'D':
                s = line[2:line.index(',')]
                c = line[line.index(',')+2:line.index(',', line.index(',')+1)]
                e = line[line.index(',', line.index(',')+1)+2:-1]
                self.delta.append([s, c, e])
            
            if line[0] == 'T':
                t = line[2:-1]
                o = self.run(t)
                outputs.append(o)
    
        f.close()

        w = open(file, 'w')
        for line in l:
            if line[0] == 'O':
                line = line[:2] + outputs[0] + line[-1:]
                outputs = outputs[1:]

            w.write(line)
        
        w.close()

    def run(self, tape):
        state = self.beginState
        for c in tape:
            for d in self.delta:
                if d[0] == '@':
                    state == d[2]
                
                elif d[0] == state and d[1] == c:
                    state = d[2]
                    break
                    
        if [state, 1] in self.states:
            return "Accepted"
        else:
            return "Rejected"                        



# 2
class Generator():
    def __init__(self, file):
        f = open(file, "r")

        self.states = []
        self.delta = []
        
        for line in f:            
            if line[0] == 'A':
                self.alphabet = line[2:]
                
            if line[0] == 'S':
                self.states.append([line[2:len(line)-4], int(line[len(line)-2:len(line)-1])])

            if line[0] == 'B':
                self.beginState = line[2:-1]

            if line[0] == 'D':
                s = line[2:line.index(',')]
                c = line[line.index(',')+2:line.index(',', line.index(',')+1)]
                e = line[line.index(',', line.index(',')+1)+2:-1]
                self.delta.append([s, c, e])

        f.close()

        output = file[:file.find('.')] + ".gv"
        tab = "   "
        w = open(output, 'w')
        
        w.write("digraph finite_state_machine {\n")
        w.write(tab + 'rankdir=LR;\n')
        w.write(tab + '_ize="8,5"\n\n')
        w.write(tab + 'node [shape = point] x\n')
        
        for state in self.states:
            w.write(tab + "node [shape = ") 
            if state[1]:
                w.write("doublecircle] " + state[0] + "\n")
            else:
                w.write("circle] " + state[0] + "\n")
        
        w.write("\n" + tab + "x -> " + self.beginState + "\n")

        for delta in self.delta:
            w.write(tab + delta[0] + " -> " + delta[2] + ' [label = "')
            for d in self.delta:
                if delta[0] == d[0] and delta[2] == d[2] and delta != d:
                    delta[1] += (", " + d[1])
                    self.delta.remove(d)

            w.write(delta[1] + '"]\n')

        w.write("}")

        w.close()

#s = Simulator("3.fsa")
#g = Generator("3.fsa")

g = Generator("1.ndfsa")
g = Generator("3.ndfsa")
g = Generator("5.ndfsa")
g = Generator("6.fsa")

s = Simulator("1.ndfsa")
s = Simulator("3.ndfsa")
s = Simulator("5.ndfsa")
s = Simulator("6.fsa")