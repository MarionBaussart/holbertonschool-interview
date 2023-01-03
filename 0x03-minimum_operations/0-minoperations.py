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
    if n <= 1:
        return 0
    a = 1
    b = 1
    while a <= b:
        for i in range(1, n):
            if n % i == 0:
                a = i
                b = n / i
                if a == b or a > b:
                    return int(a + b)
        return n
