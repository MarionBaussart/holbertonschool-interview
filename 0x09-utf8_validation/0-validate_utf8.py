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
        if data[i] > 247:
            return False

        if data[i] > 255 or data[i] < 0:
            return False

        # 0000 0000 to 1011 1111
        if data[i]>>4 <= 11:
            i += 1

        # 1100 0000 to 1101 1111
        elif data[i]>>4 <= 13:
            if i + 1 < len(data):
                # 1000 0000 to 1011 1111
                if 8 <= data[i + 1]>>4 <= 11:
                    i += 2
                else:
                    return False
            else:
                return False

        # 1110 0000 to 1110 1111
        elif data[i]>>4 == 14:
            if i + 2 < len(data):
                # 1000 0000 to 1011 1111
                if 8 <= data[i + 1]>>4 <= 11 and 8 <= data[i + 2]>>4 <= 11:
                    i += 3
                else:
                    return False
            else:
                return False

        # 1111 0000 to 1111 0111
        elif data[i]>>4 == 15:
            if i + 3 < len(data):
                # 1000 0000 to 1011 1111
                if 8 <= data[i + 1]>>4 <= 11 and \
                    8 <= data[i + 2]>>4 <= 11 and \
                    8 <= data[i + 3]>>4 <= 11:
                    i += 4
                else:
                    return False
            else:
                return False

    return True
