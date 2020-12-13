p = lambda n : ( n *(3*n - 1) ) // 2

N = 10000
pns = [p(n) for n in range(N)]

for j in range(1, N//2):
    for k in range(j+1, N//2):
        a = pns[j] + pns[k]
        b = pns[k] - pns[j]

        if a in pns and b in pns:
            print(j,k,b)
