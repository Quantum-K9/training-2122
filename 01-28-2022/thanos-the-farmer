 
 #original problem: https://codeforces.com/group/Sw3sdIlMPV/contest/264681/submission/144306133
 
low = 1
high = 1000000000

throws = 0

found = False

while not found:

    #do something

    middle =  int( (low+high)/2 )

    if throws == 29:
        print("answer",middle)
        break

    print( "throw",middle)
    throws += 1

    response = input()


    #make a decision to narrow our search space

    if response == "orbit":

        high = middle-1

    elif response == "survive":

        low = middle + 1

    else: #break

        print( "answer",middle )
        found = True
        
print(throws)
