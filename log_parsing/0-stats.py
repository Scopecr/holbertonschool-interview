import sys
import re
from collections import defaultdict

# Define the regular expression to match the input format
log_pattern = r'(\d+\.\d+\.\d+\.\d+) - \[([^\]]+)\] "GET /projects/\d+ HTTP/1.1" (\d{3}) (\d+)'

# Initialize the variables
total_size = 0
status_code_count = defaultdict(int)
line_count = 0

try:
    # Read the stdin line by line
    for line in sys.stdin:
        line = line.strip()
        match = re.match(log_pattern, line)
        
        # If line matches the expected format, process it
        if match:
            ip_address, date, status_code, file_size = match.groups()
            
            # Increment total size and status code count
            total_size += int(file_size)
            if status_code in {'200', '301', '400', '401', '403', '404', '405', '500'}:
                status_code_count[status_code] += 1

            line_count += 1

        # After every 10 lines or keyboard interruption, print statistics
        if line_count % 10 == 0:
            print(f"Total file size: {total_size}")
            for status_code in sorted(status_code_count.keys()):
                print(f"{status_code}: {status_code_count[status_code]}")

except KeyboardInterrupt:
    # Handle keyboard interruption gracefully
    print("\nKeyboard Interrupt. Final statistics:")
    print(f"Total file size: {total_size}")
    for status_code in sorted(status_code_count.keys()):
        print(f"{status_code}: {status_code_count[status_code]}")
