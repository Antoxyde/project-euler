def check(n):
    return (str(n) == str(n)[::-1]) and (bin(n)[2:] == bin(n)[2:][::-1])

print(sum(i for i in range(1000000) if check(i)))
