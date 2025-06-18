#!/usr/bin/bash/python3
'''
Making Change - Dynamic Programming Solution
'''

def makingChange(coins, total):
  '''
  Determine thefwest number of coins needed to meet a given amount total.
  Args:
    coins : List of coin values(positive intergers).
    total : Target amount to make change for.
    
    Returns:
        int: Fewest number of coins needed, or -1 if impossible, or 0 if total <= 0
  '''
  # Handle edge cases
  if total <= 0 :
    return 0
  
  if not coins:
    return -1
  
  
  #initialize DP array with infinity for all amounts except 0
  #dp [i] represents minimun coins needed to make amount i
  dp = [float('inf')] * (total + 1)
  dp[0] = 0  # 0 coins needed to make amount 0
  
  #For ecah amount from 1 to total
  for amount in range(1, total + 1):
    #try each coin denominations
    for coin in coins:
      if coins <= amount:
        #if coin can be used to make the amount
        dp[amount] = min(dp[amount], dp[amount - coin] + 1)
  
  #Return result: -1 if impossible, otherwise minimun coins needed
  return -1 if  dp[total] == float('inf') else dp[total]
