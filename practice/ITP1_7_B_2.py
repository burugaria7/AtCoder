import itertools
while True:
    n, x = map(int, input().split())
    if n == x == 0:
        break
    ans = 0
    for i,j,k in itertools.combinations(range(1,n+1),3):
        if i+j+k==x:
            ans+=1
    print(ans)