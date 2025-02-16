#!/usr/bin/python3
"""
A script that reads stdin line by line and computes metrics.
Input format: <IP Address> - [<date>] "GET /projects/260 HTTP/1.1" <status code> <file size>
After every 10 lines and/or keyboard interruption, prints statistics including:
- Total file size
- Number of lines by status code (200, 301, 400, 401, 403, 404, 405, 500)
"""
import sys


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


def extract_metrics(line):
    """Extract metrics from a line.
    
    Args:
        line (str): Input line to process
        
    Returns:
        tuple: (status_code, file_size) or (None, None) if invalid
    """
    try:
        *_, status_code, file_size = line.split()
        return int(status_code), int(file_size)
    except (ValueError, IndexError):
        return None, None


def main():
    """Main function to process the log file and compute metrics."""
    total_size = 0
    line_count = 0
    status_codes = {
        200: 0, 301: 0, 400: 0, 401: 0,
        403: 0, 404: 0, 405: 0, 500: 0
    }
    
    try:
        for line in sys.stdin:
            status_code, file_size = extract_metrics(line)
            
            if status_code is not None and file_size is not None:
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


if __name__ == "__main__":
    main()
