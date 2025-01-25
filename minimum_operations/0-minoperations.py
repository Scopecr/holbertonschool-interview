#!/usr/bin/python3
def minOperations(n):
    if n <= 1:
        return 0
        
    operations = 0
    d = 2
    
    while n > 1:
        while n % d == 0:
            operations += d  # d operations: 1 copy + (d-1) pastes
            n //= d
        d += 1
        
    return operations
  