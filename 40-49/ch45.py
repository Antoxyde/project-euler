h = lambda n : n * (2*n - 1)
p = lambda n : (n * (3 * n - 1)) // 2
t = lambda n : (n * (n + 1)) // 2

tns, pns, hns = [],[],[]
N = 100000

for i in range(N):
    tns.append(t(i))
    pns.append(p(i))
    hns.append(h(i))

for i in range(285,N):
    if tns[i] in pns and tns[i] in hns:
        print(tns[i])

