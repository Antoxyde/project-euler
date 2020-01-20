d = "0"

i = 1
while len(d) < 1000001:
    d += str(i)
    i += 1

print(int(d[1]) * int(d[10]) * int(d[100]) * int(d[1000]) * int(d[10000]) * int(d[100000]) * int(d[1000000]))

