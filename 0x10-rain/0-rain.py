#!/usr/bin/python3
"""
module containing function rain
"""


def rain(walls):
    """
    function that calculate how many square units of water will be retained
        after it rains
    Args:
        walls: list of non-negative integers
    Return: Integer indicating total amount of rainwater retained
    """
    if not walls:
        return 0

    i = 0
    rain = 0
    while i < len(walls):
        if walls[i] < 0:
            return 0
        if walls[i] != 0 and i != len(walls) - 1:
            left_wall = walls[i]
            left_index = i
            i += 1
            while walls[i] == 0 and i != len(walls) - 1:
                i += 1
            if walls[i] != 0:
                right_wall = walls[i]
                right_index = i
                rain += min(left_wall, right_wall) *\
                    (right_index - left_index - 1)
            i -= 1
        i += 1
    return rain
