#Largest Prime Factor Module
import lib_project_euler
import math
import datetime

def largest_prime_factor(n):
    """
    This function will get the largest prime factor of the input integer
    Returns: The largest prime factor if found, None otherwise
    """
    print(datetime.datetime.now().time().isoformat())
    for i in range(2, n):
        if n % i == 0 and lib_project_euler.is_prime(n/i):
            return n/i
    return None

if __name__ == "__main__":
    import sys
    print(largest_prime_factor(int(sys.argv[1])))
    print(datetime.datetime.now().time().isoformat())
