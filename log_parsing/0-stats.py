#!/usr/bin/python3
"""
<<<<<<< HEAD
Reads stdin line by line and computes metrics
"""

from sys import stdin

if name == "main":
    total_size = 0
    status_codes = {}
    list_status_codes = [
            "200", "301", "400", "401", "403", "404", "405", "500"]
    for status in list_status_codes:
        status_codes[status] = 0
    count = 0
    try:
        for line in stdin:
            try:
                args = line.split(" ")
                if len(args) != 9:
                    pass
                if args[-2] in list_status_codes:
                    status_codes[args[-2]] += 1
                if args[-1][-1] == '\n':
                    args[-1][:-1]
                total_size += int(args[-1])
            except (IndexError, ValueError):
                pass
            count += 1
            if count % 10 == 0:
                print("File size: {}".format(total_size))
                for status in sorted(status_codes.keys()):
                    if status_codes[status] != 0:
                        print("{}: {}".format(
                            status, status_codes[status]))
        print("File size: {}".format(total_size))
        for status in sorted(status_codes.keys()):
            if status_codes[status] != 0:
                print("{}: {}".format(status, status_codes[status]))
    except KeyboardInterrupt as err:
        print("File size: {}".format(total_size))
        for status in sorted(status_codes.keys()):
            if status_codes[status] != 0:
                print("{}: {}".format(status, status_codes[status]))
        raise
=======
A script that reads stdin line by line and computes metrics.
Input format: <IP Address> - [<date>] "GET /projects/260 HTTP/1.1" <status code> <file size>
After every 10 lines and/or keyboard interruption, prints statistics including:
- Total file size
- Number of lines by status code (200, 301, 400, 401, 403, 404, 405, 500)
"""
import sys
import re


def print_stats(total_size, status_codes):
    """Print the statistics of the parsed log file.
    
    Args:
        total_size (int): The total size of all processed files
        status_codes (dict): Dictionary containing counts of each status code
    """
    print(f"File size: {total_size}")
    for code in sorted(status_codes.keys()):
        if status_codes[code] > 0:
            print(f"{code}: {status_codes[code]}")


def main():
    """Main function to process the log file and compute metrics."""
    total_size = 0
    line_count = 0
    status_codes = {
        200: 0, 301: 0, 400: 0, 401: 0,
        403: 0, 404: 0, 405: 0, 500: 0
    }
    
    # Pattern to match the exact format
    pattern = r'^\S+ - \[.+\] "GET /projects/260 HTTP/1\.1" (\d+) (\d+)$'
    
    try:
        for line in sys.stdin:
            match = re.match(pattern, line.strip())
            if match:
                status_code = int(match.group(1))
                file_size = int(match.group(2))
                
                if status_code in status_codes:
                    status_codes[status_code] += 1
                total_size += file_size
                
                line_count += 1
                if line_count % 10 == 0:
                    print_stats(total_size, status_codes)
    except KeyboardInterrupt:
        pass
    finally:
        print_stats(total_size, status_codes)

>>>>>>> 7c799e6d74b95807d242e9412b6844735aae4207

if name == "main":
    main()