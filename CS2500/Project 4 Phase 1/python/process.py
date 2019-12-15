

f = open("mocities.dat", 'r')

data = []

for line in f:
    if "<br>" in line:
        line = line[4:-1]
        
        if 'MO' in line:
            line = line[0:-4]
        
        if '+' in line:
            line = line[line.index(' ')+1:]
            line = line[0:line.index(' ')] + ', -' + line[line.index('-')+2:] 
            line = line[0:3] + '.' + line[3:]
            line = line[0:15] + '.' + line[15:]

        data.append(line)

f.close()

f = open('data.csv', 'w')

for i in range(0, len(data)-1, 2):
    f.write(data[i] + ', ' + data[i+1] + '\n')

f.close()