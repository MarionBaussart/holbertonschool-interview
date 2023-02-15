#!/usr/bin/python3
"""
module containing function validUTF8
"""


def validUTF8(data):
    """
    function that determines if a given data set
        represents a valid UTF-8 encoding
    Args:
        data: data set represented by a list of integers
    Return: True if data is a valid UTF-8 encoding, else return False
    """
    i = 0
    while i < len(data):
        if data[i] > 247 or data[i] < 0:
            return False

        # 0000 0000 to 1011 1111
        if data[i] <= 191:
            i += 1

        # 1100 0000 to 1101 1111
        elif 192 <= data[i] <= 223:
            if i + 1 < len(data):
                # 1000 0000 to 1011 1111
                if 128 <= data[i + 1] <= 191:
                    i += 2
                else:
                    return False
            else:
                return False

        # 1110 0000 to 1110 1111
        elif 224 <= data[i] <= 239:
            if i + 2 < len(data):
                # 1000 0000 to 1011 1111
                if 128 <= data[i + 1] <= 191 and 128 <= data[i + 2] <= 191:
                    i += 3
                else:
                    return False
            else:
                return False

        # 1111 0000 to 1111 0111
        elif 240 <= data[i] <= 247:
            if i + 3 < len(data):
                # 1000 0000 to 1011 1111
                if 128 <= data[i + 1] <= 191 and \
                    128 <= data[i + 2] <= 191 and \
                        128 <= data[i + 3] <= 191:
                    i += 4
                else:
                    return False
            else:
                return False

    return True
