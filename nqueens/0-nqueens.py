#!/usr/bin/env python3
import sys

def solve_n_queens(n):
	"""
	Solve the N-Queens problem and return all possible solutions.

	Args:
		n (int): Size of the chessboard and number of queens to place

	Returns:
		list: A list of solutions, where each solution is a list of [row, col] positions
	"""
	def is_safe(solution, row, col):
		"""
		Check if a queen can be placed at the given position.

		Args:
			solution (list): Current solution (list of placed queens)
			row (int): Row of the new queen
			col (int): Column of the new queen

		Returns:
			bool: True if queen can be placed safely, False otherwise
		"""
		for queen_row, queen_col in solution:
			# Check same column
			if queen_col == col:
				return False

			# Check diagonals
			if abs(queen_row - row) == abs(queen_col - col):
				return False

		return True

	def solve(n):
		"""
		Recursive backtracking function to solve N-Queens problem

		Args:
			n (int): Size of the board

		Returns:
			list: List of all possible solutions
		"""
		def backtrack(row, solution):
			# If all queens are placed, add solution to solutions list
			if row == n:
				solutions.append(list(solution))
				return

			# Try placing queen in each column of current row
			for col in range(n):
				if is_safe(solution, row, col):
					# Place queen
					solution.append([row, col])

					# Recurse to next row
					backtrack(row + 1, solution)

					# Backtrack
					solution.pop()

		solutions = []
		backtrack(0, [])
		return solutions

	return solve(n)

def main():
	# Check number of arguments
	if len(sys.argv) != 2:
		print("Usage: nqueens N")
		sys.exit(1)

	# Validate input
	try:
		n = int(sys.argv[1])
	except ValueError:
		print("N must be a number")
		sys.exit(1)

	# Check N is at least 4
	if n < 4:
		print("N must be at least 4")
		sys.exit(1)

	# Solve and print solutions
	solutions = solve_n_queens(n)

	# Print each solution
	for solution in solutions:
		print(solution)

if __name__ == "__main__":
	main()
