import math
#need a function to get the number of divisors
def nofactors(n):
    count = 0
    for i in range(1, math.ceil(math.sqrt(n))):
        if n % i == 0:
            count += 2
    return count

if __name__ == '__main__':
    trinum = 1
    counter = 2
    while True:
        factors = nofactors(trinum)
        print(factors)
        if factors >= 500:
            break
        trinum += counter
        counter += 1
    print('found: ' + str(trinum))
