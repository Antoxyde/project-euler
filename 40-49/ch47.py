from sage.all import factor

def check(f0, f1, f2, f3):

    for f in f0:
        if f in f1 or f in f2 or f in f3:
            return False

    for f in f1:
        if f in f2 or f in f3:
            return False
    for f in f2:
        if f in f3:
            return False

    return True


a0,a1,a2,a3 = 1,2,3,4

while True:

    f0 = factor(a0)
    if len(f0) == 4:
        f1 = factor(a1)
        if len(f1) == 4:
            f2 = factor(a2)
            if len(f2) == 4 :
                f3 = factor(a3)
                if len(f3) == 4 and check(f0, f1, f2, f3):
                    print(a0,a1,a2,a3)
                    print("a0 = {}, a1 = {}, a2  = {}, a3 = {}".format(f0, f1, f2, f3))


    a0,a1,a2,a3 = a1,a2,a3,a3 + 1

