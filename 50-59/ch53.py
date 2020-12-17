from math import factorial

def binomial(n,r):
    return factorial(n) / (factorial(r) * factorial(n - r))

cnt = 0
for n in range(101):
    for r in range(n):
        if binomial(n,r) > 1000000:
            cnt += 1
print(cnt)
