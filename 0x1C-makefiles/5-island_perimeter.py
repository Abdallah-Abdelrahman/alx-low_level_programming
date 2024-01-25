#!/usr/bin/python3
'''Module defines `island_perimeter` function
'''


def island_perimeter(grid):
    '''returns the perimeter of the island.

    Args:
        grid(list:list:int):
            - 0 represents a water zone
            - 1 represents a land zone
            - One cell is a square with side length 1
            - Grid cells are connected horizontally/vertically (not diagonally)
            - Grid is rectangular, width and height don't exceed 100
    Returns:
        perimeter
    '''

    _len = len(grid)
    count = 0

    for row in range(_len):
        for col in range(len(grid[row])):
            if grid[row][col] == 1:
                if col == 0 or col == len(grid[row]) - 1:
                    # corners
                    count += 1
                if col != len(grid[row]) - 1 and grid[row][col + 1] == 0:
                    # right
                    count += 1
                if col != 0 and grid[row][col - 1] == 0:
                    # left
                    count += 1
                if row == _len - 1 or grid[row + 1][col] == 0:
                    # down
                    count += 1
                if row == 0 or grid[row - 1][col] == 0:
                    # top
                    count += 1

    return count
