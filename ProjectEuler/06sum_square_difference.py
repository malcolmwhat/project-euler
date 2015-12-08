# -*- coding: utf-8 -*-
import math

def sum_squared(n):
    result = 0
    for i in range(1, n+1):
        #Sum up the values
        result += i

    #return the square of the sum
    return math.pow(result, 2)


def sumof_squares(n):
    result = 0
    for i in range(1, n+1):
        #Sum up the squares
        result += math.pow(i, 2)

    #return the sum of the squares
    return result

if __name__ == '__main__':
    import sys
    n = int(sys.argv[1])
    print(sum_squared(n) - sumof_squares(n))
