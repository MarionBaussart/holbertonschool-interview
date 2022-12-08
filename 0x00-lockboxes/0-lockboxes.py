#!/usr/bin/env python3
"""method that determines if all the boxes can be opened"""


def canUnlockAll(boxes):
    """function that determines if all the boxes can be opened
       A key with the same number as a box opens that box
        Args:
            boxes is a list of lists
        Return:
            True if all boxes can be opened, else return False
    """
    keys = [0]
    for i in range(len(boxes)):
        for key in boxes[i]:
            if key != i and key not in keys:
                keys.append(key)
    return len(boxes) == len(keys)
