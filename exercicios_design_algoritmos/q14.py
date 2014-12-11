#! /usr/bin/python3

def reorder(numbers, l, r):
  i = l
  j = r

  while numbers[i]<0:
    i = i + 1

  while numbers[j]>0:
    j = j -1

  numbers[i], numbers[j] = numbers[j], numbers[i]
  return (i, j)

def divide(numbers, l, r):
  if l<r:
    s = reorder(numbers, l, r)
    divide(numbers, s[0]+1, s[1]-1)



numbers = [0, -9, 2, 4, -7, -8, 18, -3]
print(numbers)
divide(numbers, 0, len(numbers)-1)
print(numbers)
