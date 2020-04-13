def GCD(a, b):
  if b == 0:
    return a
  return GCD(b, a % b)
  
def DecipherCommonDivisor(first_ciphertext, first_modulo, first_exponent, second_ciphertext, second_modulo, second_exponent):
  # Fix this implementation to correctly decipher both messages in case
  # first_modulo and second_modulo share a prime factor, and return
  # a pair (first_message, second_message). The implementation below won't work
  # if the common_prime is bigger than 1000000.
  common_prime = GCD(first_modulo, second_modulo)
  
  q1 = first_modulo // common_prime
  q2 = second_modulo // common_prime
  return (Decrypt(first_ciphertext, common_prime, q1, first_exponent), Decrypt(second_ciphertext, common_prime, q2, second_exponent))

