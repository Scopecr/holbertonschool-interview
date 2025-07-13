
# Island Perimeter

## Description

This repository provides a Python function, `island_perimeter`, that calculates the perimeter of an island represented in a 2D grid. The grid consists of `0`s (water) and `1`s (land). Each cell is a square of side length 1, and the island is surrounded by water with no internal lakes.

## Files

- `0-island_perimeter.py`: Contains the implementation of the `island_perimeter` function.
- `0-main.py`: Example script demonstrating how to use `island_perimeter`.

## Requirements

- Python 3.x

## Usage

1. Clone or download this repository.
2. Ensure you have Python 3 installed.
3. Run the example:
   ```bash
   chmod +x 0-main.py
   ./0-main.py

```
def island_perimeter(grid):
    """
    :param grid: list[list[int]] where 1=land, 0=water
    :return: int perimeter of the single island
    """
```

## Examples
```
from 0-island_perimeter import island_perimeter

grid = [
    [0, 0, 0, 0, 0, 0],
    [0, 1, 0, 0, 0, 0],
    [0, 1, 0, 0, 0, 0],
    [0, 1, 1, 1, 0, 0],
    [0, 0, 0, 0, 0, 0]
]
print(island_perimeter(grid))  # Output: 12
```

