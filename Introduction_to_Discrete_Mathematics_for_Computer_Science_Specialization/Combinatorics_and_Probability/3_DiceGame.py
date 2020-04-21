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
    
    
def compute_strategy(dices):
  assert all(len(dice) == 6 for dice in dices)
  dicesV = dict()
  strategy = dict()
  strategy["choose_first"] = False
  
  for i in range(len(dices)):
    for j in range(i+1,len(dices)):
      a1,b1 = count_wins(dices[i], dices[j])
      if(a1>b1):
        if j not in dicesV:
          dicesV[j] = [i]
        else:
          dicesV[j] = dicesV[j] + [i]
      elif(a1<b1):
        if i not in dicesV:
          dicesV[i] = [j]
        else:
          dicesV[i] = dicesV[i] + [j]
      print( i,j)
      print(dicesV)
  temp = dict()          
  if(len(dicesV) < len(dices)):
    strategy["choose_first"] = True
    
  for i in range(len(dices)):
    if(strategy["choose_first"] == True):
      if i not in dicesV:
        strategy["first_dice"] = i
        return strategy
    else:
      temp[i] = dicesV[i][0]
  
  temp["choose_first"] = False    
  return temp
