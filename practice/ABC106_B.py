def yakusu(n):
    d = []
    for i in range(1, int(n ** 0.5) + 1):
        if n % i == 0:
            d.append(i)
            if i != n // i:
                d.append(n // i)
    return len(sorted(d))

nn = int(input())
ans=0
for i in range(nn):
    if i%2!=0:
        continue
    # print(i+1,yakusu(i+1))
    if yakusu(i+1)==8:
        ans+=1
print(ans)