
n = int(input())
state = 1
drankm =1
drankh = 1
s = input()
for i in range(n):
    state <<= 1
    if(s[i] == 'H'):
        drankh += state
    else:
        drankm += state

if(drankh < drankm):
    print("H")
elif(drankm < drankh):
    print("M")
else:
    print("HM")