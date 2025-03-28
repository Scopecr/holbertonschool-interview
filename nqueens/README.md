# N-Queens Problem

This project contains a Python implementation of the N-Queens problem. The N-Queens problem is a classic combinatorial problem that involves placing `N` chess queens on an `N×N` chessboard so that no two queens threaten each other. This means that no two queens can share the same row, column, or diagonal.

## File Structure

- **`0-nqueens.py`**: The main Python script that solves the N-Queens problem using a backtracking algorithm.

## Usage

To run the program, use the following command:

```bash
./0-nqueens.py N
```

Where `N` is the size of the chessboard and the number of queens to place. For example:

```bash
./0-nqueens.py 4
```

### Requirements

- `N` must be an integer.
- `N` must be at least 4. If `N` is less than 4, the program will display an error message and exit.

### Output

The program outputs all possible solutions for the given `N`. Each solution is represented as a list of `[row, column]` positions for the queens. For example, for `N = 4`, one possible solution is:

```plaintext
[[0, 1], [1, 3], [2, 0], [3, 2]]
```

Each sublist represents the position of a queen, where the first element is the row index and the second element is the column index.

## Example

Running the program with `N = 4`:

```bash
./0-nqueens.py 4
```

Output:

```plaintext
[[0, 1], [1, 3], [2, 0], [3, 2]]
[[0, 2], [1, 0], [2, 3], [3, 1]]
```

## Algorithm

The program uses a **backtracking algorithm** to solve the problem. It places queens row by row, ensuring that each placement is safe (i.e., no two queens threaten each other). If a placement leads to a conflict, the program backtracks and tries a different position.

## Error Handling

- If the number of arguments is not exactly 1, the program displays:
    ```plaintext
    Usage: nqueens N
    ```
- If `N` is not a valid integer, the program displays:
    ```plaintext
    N must be a number
    ```
- If `N` is less than 4, the program displays:
    ```plaintext
    N must be at least 4
    ```

## Author

This project is part of the Holberton School interview preparation curriculum.