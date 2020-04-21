def count_wins(dice1, dice2):
  assert len(dice1) == 6 and len(dice2) == 6
  dice1_wins, dice2_wins = 0, 0
    
  for i in range(6):
    for j in range(6):
      if dice1[i]>dice2[j]:
        dice1_wins = dice1_wins+1
      elif dice1[i]<dice2[j]:
        dice2_wins = dice2_wins+1
  return (dice1_wins, dice2_wins)
  
def find_the_best_dice(dices):
  assert all(len(dice) == 6 for dice in dices)
  a1,b1 = count_wins(dices[0], dices[1])
  b2,c1 = count_wins(dices[1], dices[2])
  c2,a2 = count_wins(dices[2], dices[0])
  
  if((a1>b1) and (a2>c2)):
    return 1
  if((a1<b1) and (b2>c1)):
    return 2
  if((c1>b2) and (a2<c2)):
    return 3
    # write your code here
    # use your implementation of count_wins method if necessary
  
  return -1
