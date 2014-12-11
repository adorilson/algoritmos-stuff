#! /usr/bin/python3

def world_series_odd(n):
  F = []
  f = []
  for x in range(n):
    f.append(None)
  for y in range(n):
      F.append(f[:])

  step = 0.5/n
  F[0][0] = 0.5 # no inicio todos tem 50% de chances
  for j in range(1, n):
    F[0][j] = F[0][j-1] + step
    F[j][0] = F[j-1][0] - step
  
  for i in range(1, n):
    for j in range(1, n):
      F[i][j] = (F[i-1][j] + F[i][j-1])/2

  return F

print(world_series_odd(5))


def world_series_oddR(n, i, j):
  step = 0.5/n
  
  if i==0:
    return 0.5 + step*j

  if j==0:
    return 0.5 - step*i

  return (world_series_oddR(n, i-1, j) + world_series_oddR(n, i, j-1))/2

print("Recursivo")
print(world_series_oddR(5, 2, 4))

def world_series_oddR2(n, i, j, p):
  q = 1-p
  step = q/n
  
  if i==0:
    return p + step*j

  if j==0:
    return p - step*i

  return (world_series_oddR2(n, i-1, j, p)*p + world_series_oddR2(n, i, j-1, p)*q)

print("Recursivo com probabilidades diferentes")
print(world_series_oddR2(5, 2, 4, 0.4))

