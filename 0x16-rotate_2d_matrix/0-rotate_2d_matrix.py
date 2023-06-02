#!/usr/bin/env python3
"""
module containing function rotate_2d_matrix
"""


def rotate_2d_matrix(matrix):
    """
    function that rotate an n x n 2D matrix, 90 degrees clockwise
    Args:
        matrix: n x n 2D matrix
    Return: No return
    """
    n = len(matrix)
    for i in range(int(n / 2)):
        for j in range(i, (n - 1) - i):
            tmp = matrix[i][j]
            matrix[i][j] = matrix[(n - 1) - j][i]
            matrix[(n - 1) - j][i] = matrix[(n - 1) - i][(n - 1) - j]
            matrix[(n - 1) - i][(n - 1) - j] = matrix[j][(n - 1) - i]
            matrix[j][(n - 1) - i] = tmp
