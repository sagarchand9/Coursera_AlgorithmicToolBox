def DecipherSmallPrime(ciphertext, modulo, exponent):
  if modulo % 2 == 0:
    small_prime = 2
    big_prime = modulo // 2
    return Decrypt(ciphertext, small_prime, big_prime, exponent) 

  for i in range(3, 1000000, 2):
    if modulo % i == 0:
      small_prime = i
      big_prime = modulo // i
      return Decrypt(ciphertext, small_prime, big_prime, exponent) 
  return "don't know"
