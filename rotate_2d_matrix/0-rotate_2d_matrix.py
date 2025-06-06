#!/usr/bin/python3
"""
Rotate 2D Matrix 90 degrees clockwise in-place
"""


def rotate_2d_matrix(matrix):
    """
    Rotate an n x n 2D matrix 90 degrees clockwise in-place.

    Args:
        matrix: n x n 2D list representing the matrix to rotate

    The rotation is performed by processing concentric layers of the matrix.
    For each layer, we rotate groups of 4 elements in cycles.
    """
    n = len(matrix)


    # Process each concentric layer
    for layer in range(n // 2):
        # For each element in the current layer (excluding the last one to avoid double processing)
        for i in range(layer, n - layer - 1):
            # Store the top element temporarily
            temp = matrix[layer][i]

            # Move left to top
            matrix[layer][i] = matrix[n - 1 - i][layer]

            # Move bottom to left  
            matrix[n - 1 - i][layer] = matrix[n - 1 - layer][n - 1 - i]

            # Move right to bottom
            matrix[n - 1 - layer][n - 1 - i] = matrix[i][n - 1 - layer]

            # Move top (temp) to right
            matrix[i][n - 1 - layer] = temp