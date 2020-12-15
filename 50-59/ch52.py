
x = 1
while True:

    s = sorted(str(x))
    ok = True
    for i in range(2,7):
        if sorted(str(i*x)) != s:
            ok = False
            break

    if ok:
        print(x)
        break
    x += 1
