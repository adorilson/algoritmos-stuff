#! /usr/bin/python3

def cutRod(prices):
  if not prices:
    return 0

  max_val = 0

  for i in range(len(prices)):
    next_val = prices[i] + cutRod(prices[:len(prices)-i-1])
    max_val = max(max_val, next_val)

  return max_val

numbers = [1, 5, 8, 9, 10, 17, 17, 20]
print(numbers)
print(cutRod(numbers))

numbers = [3, 5, 8, 9, 10, 17, 17, 20]
print(numbers)
print(cutRod(numbers))

