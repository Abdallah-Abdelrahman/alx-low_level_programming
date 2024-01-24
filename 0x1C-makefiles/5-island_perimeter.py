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
#    if not isinstance(grid, list):
#        return 0

    _len = len(grid)
    w = 0
    h = 0

#    if _len == 0 or len(grid[0]):
#        return 0

    for row in range(_len):
        for col in range(len(grid[row])):
            if grid[row][col] == 1:
                cell = []
                if w == 0 or grid[row][col] != grid[row - 1][col]:
                    if len(cell) == 0:
                        w += 1
                        cell += [row, col]
                    elif abs(cell[0] - row) == abs(cell[1] - col):
                        continue
                if h == 0 and len(grid[row]) - 1 > col > 0:
                    for r in range(row, _len):
                        if grid[r][col] == 1:
                            h += 1
#    print('w = {}, h = {}'.format(w, h))
    return 2 * (w + h)
