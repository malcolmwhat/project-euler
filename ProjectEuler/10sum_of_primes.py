# This script's purpose is to calculate the sum of all primes bellow 2e6

from lib_project_euler import is_prime

def calculate_sum_of_primes(upper_lim):
    total_sum = 0
    # Pure brute force solution: Run time is about 17 seconds 
    # Not the most efficient, but it meets requirements (under a minute)
    for i in range(1, upper_lim + 1):
        if is_prime(i):
            total_sum += i
            print(i)
    return total_sum

if __name__ == "__main__":
    import sys
    print(calculate_sum_of_primes(int(sys.argv[1])))
