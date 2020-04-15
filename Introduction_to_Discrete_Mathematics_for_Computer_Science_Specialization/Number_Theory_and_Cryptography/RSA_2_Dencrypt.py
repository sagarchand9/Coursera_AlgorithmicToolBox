def Decrypt(ciphertext, p, q, exponent):
  n = (p-1)*(q-1)
  d = InvertModulo(exponent, n)
  return ConvertToStr(PowMod(ciphertext, d, p * q))
