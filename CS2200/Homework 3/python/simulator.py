




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
                line = line[:-1] + outputs[0] + line[-1:]
                outputs = outputs[1:]
                w.write(line)
            else:
                w.write(line)
        
        w.close()


    def run(self, tape):
        state = self.beginState
        for c in tape:
            for d in self.delta:
                if d[0] == state and d[1] == c:
                    state = d[2]
                    break

        if [state, 1] in self.states:
            return "Accepted"
        else:
            return "Rejected"                        
