
#original problem: https://codeforces.com/contest/431/problem/B

from itertools import permutations as p

g = []
for i in range(5):
    g.append( [ int(x) for x in input().split() ] )


listt = [ 0, 1, 2, 3, 4 ]

allPossibleOptions = list( p(listt) ) 

answer = 0

for option in allPossibleOptions:

    score = 0

    #compute for the score
    for frontPersonInLine in range(0,5):

        for pair in range( frontPersonInLine, 5, 2 ):

            if pair < 4:
                score = score + g[ option[ pair ]][ option[ pair+1] ] 
                score = score + g[ option[ pair+1]][option[pair] ] 


    answer = max( answer, score ) 

print(answer)
