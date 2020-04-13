def Encrypt(message, modulo, exponent):
  return PowMod(ConvertToInt(message), exponent, modulo)
