from itertools import *
from sage.all import is_prime
import sys

for p1 in range(1001, 10000, 2):
    if p1 != 1487 and is_prime(p1):
        for p2 in permutations(str(p1), 4):
            p2 = int("".join(p2))
            if p2 > 1000 and is_prime(p2):
                for p3 in permutations(str(p1), 4):
                    p3 = int("".join(p3))
                    if p3 != p2 and p3 > 1000 and is_prime(p3):
                        if p1 - p2 == p2 - p3:
                            print("".join(map(str, sorted([p1,p2,p3]))))
                            sys.exit()
