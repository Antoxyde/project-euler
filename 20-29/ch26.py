def rcycle(n):
    lpow=1
    while True:
        for mpow in range(lpow-1, -1, -1):
            if (10**lpow-10**mpow) % n == 0:
                return lpow-mpow
        lpow += 1

m = 0
for i in range(1, 1000):
    r = rcycle(i)
    if r > m:
        m = r
        print("new max: 1/{} : {}".format(i, rcycle(i)))
