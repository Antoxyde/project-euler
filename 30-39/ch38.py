def cp(n: int, nums):
    return "".join(map(str, [n * x for x in nums]))

def valid(n, nums):
    prod = cp(n, nums)
    return all(prod.count(x) == 1 for x in "123456789") and not "0" in prod

val = 0
for n in range(2, 10**4):
    nums = list(range(1,10))
    for i in range(2,10):
        if valid(n, nums[:i]):
            val = max(val, int(cp(n, nums[:i])))
print(val)

