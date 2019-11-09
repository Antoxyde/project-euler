def check(n):
    return n == sum(pow(int(x), 5) for x in list(str(n)))
        

result = 0
for x in range(2, 5*pow(9,5)):
    if check(x):
        print(x)
        result += x

print("Result is {}".format(result))
