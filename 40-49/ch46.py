from math import *

def is_prime(n):
    if n in [0,1]:
        return False
    if n == 2:
        return True
    if n % 2 == 0 or n == 1:
        return False


    for i in range(3, ceil(sqrt(n)) + 1, 2):
        if n%i == 0:
            return False
    return True

def is_square(n):
    s = int(sqrt(n))
    return n == s*s

N = 10000
n_primes = [i for i in range(N) if is_prime(i)]

for i in range(3, N, 2):
    if not is_prime(i):
        ok = False

        for p in n_primes:
            if p > i: break

            if is_square((i - p)//2):
                ok = True
                break
        if not ok:
            print(i)
            exit()
