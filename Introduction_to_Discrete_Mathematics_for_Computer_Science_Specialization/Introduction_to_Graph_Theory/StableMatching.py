def stableMatching(n, menPreferences, womenPreferences):
# Do not change the function definition line.

    # Initially, all n men are unmarried
    unmarriedMen = list(range(n))
    # None of the men has a spouse yet, we denote this by the value None
    manSpouse = [None] * n                      
    # None of the women has a spouse yet, we denote this by the value None
    womanSpouse = [None] * n                      
    # Each man made 0 proposals, which means that 
    # his next proposal will be to the woman number 0 in his list
    nextManChoice = [0] * n                       
    count=0
    # While there exists at least one unmarried man:
    while unmarriedMen:
        #print(unmarriedMen, manSpouse, womanSpouse)
        # Pick an arbitrary unmarried man
        he = unmarriedMen[0]                      
        # Store his ranking in this variable for convenience
        hisPreferences = menPreferences[he]       
        # Find a woman to propose to
        she = hisPreferences[nextManChoice[he]] 
        # Store her ranking in this variable for convenience
        herPreferences = womenPreferences[she]
        # Find the present husband of the selected woman (it might be None)
        currentHusband = womanSpouse[she]         
        
        # Write your code here
        currHusbandRank = -1
        currProposerRank= -1
        for i in range(len(herPreferences)):#handle the none cases
            if(currentHusband != None ):
                if(currentHusband == herPreferences[i]):
                    currHusbandRank = i
            if(he == herPreferences[i]):
                currProposerRank = i    
            
        if((currHusbandRank == -1) or (currProposerRank<currHusbandRank)):
            manSpouse[he] = she
            womanSpouse[she] = he
            count += 1
            unmarriedMen.pop(0)
            if(currHusbandRank != -1):
                unmarriedMen.append(currentHusband)
                nextManChoice[currentHusband] += 1
                count-=1
        else:
          nextManChoice[he] += 1
        
        # Now "he" proposes to "she". 
        # Decide whether "she" accepts, and update the following fields
        # 1. manSpouse
        # 2. womanSpouse
        # 3. unmarriedMen
        # 4. nextManChoice
            
    # Note that if you don't update the unmarriedMen list, 
    # then this algorithm will run forever. 
    # Thus, if you submit this default implementation,
    # you may receive "SUBMIT ERROR".

    return manSpouse
