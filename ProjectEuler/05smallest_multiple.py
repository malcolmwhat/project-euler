# -*- coding: utf-8 -*-

def multiple_in_list(int_in, list_in):
    """
    Checks if int_in is a factor of any of the elements of list_in.
    """
    for i in list_in:
        if i % int_in == 0:
            return True

    return False


def get_initial_product(max_divisor):
    """
    This calculates max_divisor factorial but excludes factors that are factors of
    larger factors.

    Ex: get_initial_product(5) -> 5*4*3*skip 2, since 2 is factor
    of 4, skip 1, since it's a factor of 5.
    """
    reduced_factors = []
    for i in range(max_divisor, 0, -1):
        #Check if there is a multiple of the current value (i) in the list
        if not multiple_in_list(i, reduced_factors):
            #if not, then add the current value to the list
            reduced_factors.append(i)

    #Now we have a list of independant factors, multiply them
    initial_product = 1
    for i in reduced_factors:
        initial_product *= i # *= -> similar to += operator, but with *

    return initial_product


def is_evenly_divisible(value, max_divisor):
    """
    This functions purpose is to check if value is evenly divisible by the
    second arg (max_divisor).
    """
    for i in range(max_divisor, 0, -1):
        #Check if it's not an even factor (no remainder)
        if value % i != 0:
            return False

    #If the loop finishes, value is evenly divisible by max_divisor
    return True


def look_for_sm(value, max_divisor):
    """
    This function's purpose is to find the smallest_multiple that is evenly
    divisible by max_divisor. What we'll do is we'll loop backwards from
    max_divisor, and call is_evenly_divisible on value / i. If the result is
    True, then we recall this function with value / i. If we get through the
    whole loop, then we've found our smallest_multiple.
    """
    for i in range(max_divisor, 1, -1):
        if is_evenly_divisible(value/i, max_divisor):
            return look_for_sm(value/i, max_divisor)

    #If we get through the loop then we've found our smallest divisor
    return value


def get_smallest_multiple(max_divisor):
    """
    This function returns the smallest multiple that is evenly divisible by
    all of the numbers from 1 to max_divisor. Basically if max_divisor is n, then the
    return value of this function is the smallest number that is divisible by
    all numbers from 1 to n.
    """
    #initial_product a reduced version of the factorial of max_divisor.
    #May actually be more readible to just use factorial, not to mention faster.
    initial_product = get_initial_product(max_divisor)
    #TODO implement recursive backwards algorithm...
    smallest_multiple = look_for_sm(initial_product, max_divisor)
    return smallest_multiple


if __name__ == '__main__':
    import sys
    print(get_smallest_multiple(int(sys.argv[1])))
