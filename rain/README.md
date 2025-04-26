# Rain

This project contains a Python script, `0-rain.py`, which calculates how much water will be retained after it rains, given a list of non-negative integers representing the heights of walls.

## Usage

To use the script, simply import the function `rain` from `0-rain.py` and pass a list of integers as an argument:

```python
from 0-rain import rain

walls = [0, 1, 0, 2, 0, 3, 0, 4]
water_retained = rain(walls)
print(water_retained)
```

## Function Description

### `rain(walls)`
- **Parameters**:
    - `walls` (list of integers): A list of non-negative integers representing the heights of walls.
- **Returns**:
    - An integer representing the total amount of water retained after it rains.
- **Edge Cases**:
    - If `walls` is empty or contains less than 3 walls, the function returns `0`.

## Example

```python
walls = [0, 1, 0, 2, 0, 3, 0, 4]
print(rain(walls))  # Output: 6
```

## Requirements
- Python 3.x

## Author
This project is part of the Holberton School Interview Preparation curriculum.