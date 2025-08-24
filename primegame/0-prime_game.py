#!/usr/bin/python3
"""Prime Game: determine the overall winner across x rounds.

Given rounds with upper bounds n_i, players alternately pick primes from
{1..n_i} and remove the prime and its multiples. With optimal play, the
number of moves in a round equals the count of primes ≤ n_i. If that
count is odd, Maria (first player) wins the round; if even, Ben wins.
"""


def isWinner(x, nums):
    """
    Determine who wins the most rounds of the prime game.

    Args:
        x (int): number of rounds
        nums (list[int]): list of n for each round

    Returns:
        str | None: "Maria", "Ben", or None if tie/undetermined
    """
    if not nums or x <= 0:
        return None

    max_n = 0
    for i in range(min(x, len(nums))):
        if nums[i] > max_n:
            max_n = nums[i]

    if max_n < 2:
        # No primes in any round; Ben always wins those rounds
        return "Ben"

    # Sieve of Eratosthenes up to max_n (no imports)
    sieve = [True] * (max_n + 1)
    sieve[0] = sieve[1] = False
    p = 2
    while p * p <= max_n:
        if sieve[p]:
            step = p
            start = p * p
            for m in range(start, max_n + 1, step):
                sieve[m] = False
        p += 1

    # Prefix count of primes: prime_count[n] = #primes <= n
    prime_count = [0] * (max_n + 1)
    count = 0
    for i in range(max_n + 1):
        if sieve[i]:
            count += 1
        prime_count[i] = count

    maria_wins = 0
    ben_wins = 0

    # Evaluate each round
    rounds = min(x, len(nums))
    for i in range(rounds):
        n = nums[i]
        # Number of moves equals number of primes <= n
        moves = prime_count[n] if n <= max_n else 0
        if moves % 2 == 1:
            maria_wins += 1
        else:
            ben_wins += 1

    if maria_wins > ben_wins:
        return "Maria"
    if ben_wins > maria_wins:
        return "Ben"
    return None
