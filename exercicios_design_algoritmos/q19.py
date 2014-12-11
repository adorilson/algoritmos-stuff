#! /usr/bin/python3

def shortestpath(n, m):
  F = []
  f = []
  for x in range(n):
    f.append(1) 
  for y in range(m):
      F.append(f[:])

  F[0][0] = 1
  for j in range(1, n):
    F[0][j] = 1
  
  for i in range(1, m):
    F[i][1] = F[i-1][0] + 1
    for j in range(n)[1:]:
      F[i][j] = F[i-1][j] + F[i][j-1]

  for f in F:
    print(f)
  return F[m-1][n-1]

print(shortestpath(4, 8))

def shortestpathR(n, m):
  if n==1 or m==1:
    return 1

  total = 0
  for i in range(1, m):
    for j in range(1, n):
      total = total + shortestpathR(i-1, j) + shortestpathR(i, j-1)

  return total

print("Recursivo")
print(shortestpathR(4, 8))
