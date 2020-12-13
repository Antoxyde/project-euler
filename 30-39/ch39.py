
# a + b + c = 1000
# and a^2 + b^2 = c^2
val = 0
for n in range(1,1000):
    solves = set()
    for a in range(n):
        for b in range(n - a + 1):
            for c in range(n - a - b + 1):
                if a + b + c == n and a**2 + b**2 == c**2:
                    solves.add(str(sorted([a,b,c])))

    if len(solves) > val:
        val =  len(solves)
        res = n

print("res", res)
