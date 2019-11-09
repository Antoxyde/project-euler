import itertools

interval = list(map(str,range(1,10)))

s = 0

for perm in itertools.permutations(interval):
    m1 = int("".join(perm[:3]))
    m2 = int("".join(perm[3:5]))
    res = int("".join(perm[5:]))
    if m1*m2 == res:
        s += res
        print(m1,m2,res)
print("Result is {}".format(s))
