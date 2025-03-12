# UTF-8 Validation

This project contains a Python implementation to validate UTF-8 encoded data according to the UTF-8 encoding specification.

## Description

The project provides a method to determine if a given data set represents a valid UTF-8 encoding. UTF-8 is a variable-width character encoding that can represent every character in the Unicode character set using 1 to 4 bytes.

### General
- Allowed editors: vi, vim, emacs
- Files will be interpreted/compiled on Ubuntu 14.04 LTS using Python 3 (version 3.4.3)
- All files end with a new line
- First line of all files is exactly `#!/usr/bin/python3`
- Code follows PEP 8 style guidelines (version 1.7.x)
- All files must be executable

### Technical
- The data set is represented as a list of integers
- Each integer represents one byte of data (only 8 least significant bits are used)
- UTF-8 characters can be 1 to 4 bytes long