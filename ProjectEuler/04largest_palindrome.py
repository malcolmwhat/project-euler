# -*- coding: utf-8 -*-
import lib_project_euler as pelib

def has_three_digit_factors(value):
    """This method checks if the input value has three digit factors, i.e.
    if the input is x, and it has any factors y and z, both of which are three
    digit, it returns True. Otherwise it returns False.
    """
    #Start the factors at 100, i.e smallest three digit num
    i = 100
    # first cond: avoid recalculation, second cond: i needs to be 3 digit
    while i*i <= value and i <= 999:
        #Checks if it's an even factor and the complement is three digit
        if value/i == int(value/i) and value/i >= 100 and value/i <= 999:
            return True
        i += 1
    return False

def largest_palindrome(maximum):
    """This is for a particular question in the project euler problem set
    the purpose of this question is to find the largest palindromic number
    smaller than the `maximum` which has 3 digit factors.
    """
    i = int(maximum)
    #Won't make it to zero if cases are respected. This is to stop inf loop
    while i >= 10000:
        if pelib.is_palindrome(i) and not pelib.is_prime(i):
            if has_three_digit_factors(i):
                return i
        i -= 1


if __name__ == "__main__":
    import sys
    print(largest_palindrome(int(sys.argv[1])))
