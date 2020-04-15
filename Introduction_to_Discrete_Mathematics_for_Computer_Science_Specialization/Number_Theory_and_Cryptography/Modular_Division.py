def gcd(a, b):
  assert a >= 0 and b >= 0 and a + b > 0

  while a > 0 and b > 0:
    if a >= b:
      a = a % b
    else:
      b = b % a
  return max(a, b)
  
def divide(a, b, n):
  assert n > 1 and a > 0 and gcd(a, n) == 1
  b = b%n
  for x in range(n):
    if(b == ((a*x)%n)):
      return x
  # return the number x s.t. x = b / a (mod n) and 0 <= x <= n-1.
  return -1
