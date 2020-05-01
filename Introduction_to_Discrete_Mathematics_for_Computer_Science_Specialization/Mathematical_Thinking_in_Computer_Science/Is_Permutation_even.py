def is_even(p):
  i = 0;
  n = len(p);
  count = 0;
  
  while( i<n ):
    if(p[i] != i):
      index = p.index(i);
      p[i], p[index] = p[index], p[i]
      count = count+1
    i = i+1

  if(count%2==0):
    return True
  return False
