from sage.all import is_prime
import sys

def get_mutated_primes(s, digit):

    prime = []
    for rep in range(10):
        n = int(s.replace(str(digit), str(rep)))
        if len(str(n)) == len(s) and is_prime(n) :
            prime.append(n)
    return prime



n = 3
while True:
    if is_prime(n):
        s = str(n) # its useless to replace the last digit
        for digit in range(10):
            cnt =  s.count(str(digit))
            if cnt >= 2:
                primes = get_mutated_primes(s, digit)
                if len(primes) == 8:
                    print(min(primes))
                    sys.exit()
    n += 2
