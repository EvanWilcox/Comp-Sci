# Evan Wilcox
# Comp Sci 2200
# NDFSA+e Graphviz Generator

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

        output = file[:file.find('.')] + ".dot"
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
