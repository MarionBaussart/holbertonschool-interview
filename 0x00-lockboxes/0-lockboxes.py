#!/usr/bin/python3
"""module that contains the canUnlockAll method"""


def canUnlockAll(boxes):
    """method that determines if all the boxes can be opened
       A key with the same number as a box opens that box
        Args:
            boxes is a list of lists
        Return:
            True if all boxes can be opened, else return False
    """
    keys = [0]
    for i in range(len(boxes)):
        for key in boxes[i]:
            if key != i and key not in keys and key < len(boxes):
                keys.append(key)
    return len(boxes) == len(keys)
