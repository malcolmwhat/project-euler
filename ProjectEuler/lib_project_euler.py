import math

def is_prime(integer_input):
    """
    This function determines whether or not a number is prime
    Args:
        integer_input: Any positive integer
    Returns:
        Boolean True if Prime, False if not
    """
    #0, 1 & 2 are all prime
    if integer_input <= 2:
        return True

    #If it's even it's not prime
    if integer_input % 2 == 0:
        return False

    #Optimized to only go to sqrt(integer_input)
    upperLim = math.ceil(math.sqrt(integer_input))
    i = 3
    while i <= upperLim:
        if integer_input % i == 0:
            return False
        i += 2
    return True

def is_palindrome(integer_input):
    """
    This function determines whether or not a number is palindrome, i.e.
    if it reads the same way backwards and forwards.
    Parameters:
        integer_input: Any positive integer
    Returns Boolean: True if palindrome, False if not
    """
    # Try casting to int, if it doesn't work, raise TypeError
    try:
        int(integer_input)
    except ValueError as error:
        raise ValueError('Must Enter A Numeric, style either "123" or 123')

    # Casts the input to str to allow the use of slice operation
    integer_input = str(integer_input)

    # Slice the string backwards, effectively reversing the string
    reversed_input = integer_input[::-1]

    #Check if the reversed is the same as the input
    if (integer_input == reversed_input):
        return True
    else:
        return False
