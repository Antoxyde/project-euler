from itertools import permutations

def check(p):
    for i,prime in enumerate([2,3,5,7,11,13,17]):
        if int(p[i+1:i+4]) % prime != 0 :
            return False
    return True

cnt = 0
for p in permutations("0123465879", 10):
    p = "".join(p)

    if "0" != p[0] and check(p):
        cnt += int(p)
print(cnt)
