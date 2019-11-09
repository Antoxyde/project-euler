def recuring_cycle(n):
    x = str(1/n)
    # Todo : there must be a math tricks to get the recuring cycle of a fraction
    # Because due to the fact that python truncate float of more ~14digitts, it's impossible to do in the naive way
    for x in range(

m = 0
md = 0
for d in range(1,1000):
    l = len(recuring_cycle(d))
    if l > md :
        m = d

print(m, md)
