path = "/home/gawor17/Documents/CP/AMPZZ/2021/J/"
modelsol = open(path + "1.out", 'r')
mysol = open(path + "out.txt", 'r')

modellines = modelsol.readlines()
sol = mysol.readlines()

for i in range(len(sol)):
    if(modellines[i] == "TAK\n" and sol[i] == "TAK\n"):
        print("Poprawnie zadanie", i+1)
    if(modellines[i] == "NIE\n" and sol[i] == "NIE\n"):
        print("Poprawnie zadanie", i+1)