def change(amount):
  if amount >=24:

    if amount == 24: #24
      return [5, 5, 7, 7 ]
    elif amount == 25:
      return [5, 5, 5, 5, 5]
    elif amount == 26: #26
      return [5, 7, 7, 7]
    elif amount == 27: #27
      return [5, 5, 5, 5, 7]
    elif amount == 28: #28
      return [7,7,7,7]
    elif amount == 29: #29
      return [5,5,5,7,7]
    elif amount == 30: #30
      return [5,5,5,5,5,5]

    ans = change(amount - 7)

    ans.append(7)
    return ans
