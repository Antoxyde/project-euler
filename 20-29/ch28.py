def sum_spiral_diagonal(n):
    s = 1
    for i in range(3, n+2, 2):    
        for x in range(4):
            s += i*i - x*i + x
    return s

print(sum_spiral_diagonal(1001))

        
