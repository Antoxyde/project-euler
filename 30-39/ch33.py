from math import gcd

def drunk_cancel(a,b):

    # yeah thats a hell of a shitty code

    d = ""

    for i,n in enumerate(str(a)):
        if n in str(b):
            aa = str(a)[:i] + str(a)[i+1:]
            index = str(b).index(n)
            bb = str(b)[:index] + str(b)[index+1:]

            try:
                aa = int(aa)
                bb = int(bb)

                r = a/b
                r2 = aa/bb

                if a != b and r == r2:
                    if a % 10 != 0 or b % 10 != 0:
                        return True

            except:
                continue
    return False

solutions = []
for a in range(10,100):
    for b in range(10,100):
        if drunk_cancel(a,b) and not (b,a) in solutions:
            solutions.append((a,b))

num , denom = 1,1
for i in range(4):
    num *= solutions[i][0]
    denom *= solutions[i][1]

print(num/gcd(num,denom),denom/gcd(num,denom))






