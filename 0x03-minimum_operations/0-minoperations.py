#!/usr/bin/python3
"""module that contains the minOperations method"""


def minOperations(n):
    """In a text file, there is a single character H.
        Your text editor can execute only two operations in this file:
            Copy All and Paste.
        Method that calculates the fewest number of operations needed
            to result in exactly n H characters in the file.
        Args:
            n: integer, number of character H to write
        Return:
            the fewest number of operations needed
    """
    i = 2
    list_prime_factors = []
    while i * i <= n:
        if n % i:
            i += 1
        else:
            n //= i
            list_prime_factors.append(i)
    if n > 1:
        list_prime_factors.append(n)
    return sum(list_prime_factors)
