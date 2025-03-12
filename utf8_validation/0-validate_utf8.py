#!/usr/bin/python3
"""
Module to validate UTF-8 encoding.

This module provides a function to determine if a given data set represents
a valid UTF-8 encoding, following the UTF-8 encoding specification where
characters can be 1 to 4 bytes long.
"""

def validUTF8(data):
    """
    Determines if a given data set represents a valid UTF-8 encoding.

    Args:
        data: List of integers representing bytes

    Returns:
        bool: True if data is valid UTF-8 encoding, False otherwise
    """
    # Helper function to check if a byte starts with '10'
    def check_continuation_byte(byte):
        return byte & 0b11000000 == 0b10000000

    # Process each byte in the data
    i = 0
    while i < len(data):
        # Get the first byte of current character
        first_byte = data[i]

        # Determine number of bytes in current character
        if first_byte & 0b10000000 == 0:  # 1-byte character
            num_bytes = 1
        elif first_byte & 0b11100000 == 0b11000000:  # 2-byte character
            num_bytes = 2
        elif first_byte & 0b11110000 == 0b11100000:  # 3-byte character
            num_bytes = 3
        elif first_byte & 0b11111000 == 0b11110000:  # 4-byte character
            num_bytes = 4
        else:
            return False

        # Check if we have enough bytes remaining
        if i + num_bytes > len(data):
            return False

        # Check all continuation bytes
        for j in range(i + 1, i + num_bytes):
            if not check_continuation_byte(data[j]):
                return False

        # Move to the next character
        i += num_bytes

    return True

# Example usage (for testing purposes)
if __name__ == "__main__":
    # Valid UTF-8 examples

    data1 = [65]  # 'A'
    data2 = [197, 130, 1]  # Valid 2-byte and 1-byte characters

    # Invalid UTF-8 examples
    data3 = [235, 140]  # Incomplete 3-byte sequence
    data4 = [255]  # Invalid start byte

    print(validUTF8(data1))  # True
    print(validUTF8(data2))  # True
    print(validUTF8(data3))  # False
    print(validUTF8(data4))  # False
