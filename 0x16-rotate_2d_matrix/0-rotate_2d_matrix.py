#!/usr/bin/python3
""" This module define the rotate_2d_matrix method """


def rotate_2d_matrix(matrix):
    """ This method rotate a 2d matrix in 90 degrees clockwise """
    n = len(matrix)

    for i in range(0, n // 2):

        for j in range(i, n - i - 1):

            tmp = matrix[i][j]
            matrix[i][j] = matrix[n - 1 - j][i]
            matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j]
            matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i]
            matrix[j][n - 1 - i] = tmp
