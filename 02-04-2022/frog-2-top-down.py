
import sys
sys.setrecursionlimit( 1000000 )

n,k = [ int(x) for x in input().split() ]
h = [ int(x) for x in input().split() ]

memo = [-1]*(n+1)

def dp(i): # the cheapest way to get from stone i tp stone n --> dp(1)

    if memo[i] != -1:
        return memo[i]
    
    if i == n-1:
        return 0

    if i == n-2:
        return abs( h[i]-h[i+1] )

    #general case: min( cost( stone i to stone i+1 ) + dp(i+1),
                    #   cost( stone i to stone i+2 ) + dp(i+2))
                    # up to k jumps

    answer = abs(h[i]-h[i+1]) + dp(i+1) # jump 1
    
    for jumpDistance in range( 1, k+1 ): #for( int i = 1; i < k+1; i++ )

        if i+jumpDistance > n-1: #too much
            break
        
        answer = min( answer, abs(h[i]-h[i+jumpDistance]) + dp(i+jumpDistance) )
                               
    memo[i] = answer
    return answer

print( dp(0) )

# 1 2 3 4 5 .... n
# 0 1 2 3 4 .... n-1
