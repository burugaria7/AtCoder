def acgt(s):
    if s == 'A' or s == 'C' or s == 'G' or s == 'T':
        return True
    else:
        return False

c1,c2 = 0,0
str = input()
for i in range(len(str)):
    if acgt(str[i]):
        c1 += 1
    else:
        c1 = 0
    if c1 > c2:
        c2 = c1
print(c2)