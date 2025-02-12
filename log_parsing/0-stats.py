#!/usr/bin/python3
import sys
import signal
import re
from collections import defaultdict

def print_statistics(total_size, status_codes):
    """Print the required statistics."""
    print(f"File size: {total_size}")
    for code in sorted(status_codes.keys()):
        # Only print status codes that are integers and in our valid set
        try:
            code_int = int(code)
            if code_int in {200, 301, 400, 401, 403, 404, 405, 500}:
                print(f"{code}: {status_codes[code]}")
        except ValueError:
            continue

def parse_line(line):
    """
    Parse a log line and return file size and status code.
    Returns None if the line format is invalid.
    """
    pattern = r'^\S+ - \[\d{4}-\d{2}-\d{2} \d{2}:\d{2}:\d{2}\.\d{6}\] "GET /projects/260 HTTP/1\.1" (\d+) (\d+)$'
    match = re.match(pattern, line)
    
    if not match:
        return None
    
    try:
        status_code = match.group(1)
        file_size = int(match.group(2))
        return status_code, file_size
    except (IndexError, ValueError):
        return None

def main():
    total_size = 0
    status_codes = defaultdict(int)
    line_count = 0
    
    def signal_handler(sig, frame):
        """Handle CTRL+C by printing statistics and exiting."""
        print_statistics(total_size, status_codes)
        sys.exit(0)
    
    # Set up signal handler for CTRL+C
    signal.signal(signal.SIGINT, signal_handler)
    
    try:
        for line in sys.stdin:
            line = line.strip()
            result = parse_line(line)
            
            if result:
                status_code, file_size = result
                total_size += file_size
                status_codes[status_code] += 1
                line_count += 1
                
                # Print statistics every 10 lines
                if line_count % 10 == 0:
                    print_statistics(total_size, status_codes)
    
    except KeyboardInterrupt:
        # Handle CTRL+C
        print_statistics(total_size, status_codes)
        sys.exit(0)

if __name__ == "__main__":
    main()
