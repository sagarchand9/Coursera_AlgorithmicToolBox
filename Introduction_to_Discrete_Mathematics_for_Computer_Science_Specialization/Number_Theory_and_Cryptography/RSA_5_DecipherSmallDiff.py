def DecipherSmallDiff(ciphertext, modulo, exponent):
  end = IntSqrt(modulo)
  start = end - 5000
  for i in range(start, end+1):
    if modulo % i == 0:
      small_prime = i
      big_prime = modulo // i
      return Decrypt(ciphertext, small_prime, big_prime, exponent)
  return "don't know"
