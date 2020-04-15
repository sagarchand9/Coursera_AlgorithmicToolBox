def lcm(a, b):
  assert a > 0 and b > 0
  prod = a*b
  if(a<b):
    a,b = b,a
  
  while(a%b > 0):
    temp = a%b
    a = b
    b = temp
  
  # Write your code here
  return prod/b
