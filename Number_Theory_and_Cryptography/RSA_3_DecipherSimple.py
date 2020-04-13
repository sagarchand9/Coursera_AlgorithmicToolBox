def DecipherSimple(ciphertext, modulo, exponent, potential_messages): 
  # Fix this implementation
  for i in range(len(potential_messages)):
    if ciphertext == Encrypt(potential_messages[i], modulo, exponent):
      return potential_messages[i]
  return "don't know"
