import collections

def solve_for(coeffs, k, rhs):

    if rhs == 0:
        return 1

    if rhs < 0  or k < 0:
        return 0

    return solve_for(coeffs, k, rhs - coeffs[k]) + solve_for(coeffs, k - 1, rhs)


print(solve_for([1,2,5,10,20,50,100,200], 7, 200))



