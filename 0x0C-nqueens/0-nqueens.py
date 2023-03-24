#!/usr/bin/python3
import sys


def add_solutions(board, solutions):
    """ Add solution into a list """
    queens_pos = []
    for i, row in enumerate(board):
        for j, col in enumerate(row):
            if col == 1:
                queens_pos.append([i, j])
    solutions.append(queens_pos)


def is_safe(board, row, col, size):
    """ Find the position to place a queen """
    for i in range(col):
        if board[row][i] == 1:
            return False

    for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
        if board[i][j] == 1:
            return False

    for i, j in zip(range(row, size, 1), range(col, -1, -1)):
        if board[i][j] == 1:
            return False
    return True


def solve_n_queens(board, col, size, solutions):
    """ Find all solutions for a board at a specific size """
    if col == size:
        add_solutions(board, solutions)
        return

    for i in range(size):
        if is_safe(board, i, col, size):
            board[i][col] = 1
            solve_n_queens(board, col + 1, size, solutions)
            board[i][col] = 0


def n_queens(size):
    """ Solve n queens challenge and display solutions """
    board = [[0 for _ in range(size)] for _ in range(size)]
    solutions = []
    solve_n_queens(board, 0, size, solutions)

    for solution in solutions:
        print(solution)


def validate():
    """ Check the command format """
    if len(sys.argv) != 2:
        print('Usage: nqueens N')
        exit(1)

    try:
        n = int(sys.argv[1])
    except Exception:
        print('N must be a number')
        exit(1)

    if n < 4:
        print('N must be at least 4')
        exit(1)

    return n


if __name__ == "__main__":

    size = validate()
    n_queens(size)
