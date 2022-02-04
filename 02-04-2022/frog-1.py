
import sys
sys.setrecursionlimit( 1000000 )

#take input
n = int( input() )
h = [ int(x) for x in input().split() ]

memo = [-1]*(n+1)

def dp(i): # the cheapest way to get from stone i to stone n-1 (last stone) --> dp(0)

    if memo[i] != -1:
        return memo[i]
    
    if i == n-1:
        return 0

    if i == n-2:
        return abs( h[i]-h[i+1] )

    #general case: min( cost( stone i to stone i+1 ) + dp(i+1),
                    #   cost( stone i to stone i+2 ) + dp(i+2))

    answer = min( abs(h[i]-h[i+1]) + dp(i+1),
                  abs(h[i]-h[i+2]) + dp(i+2) )

    memo[i] = answer
    return answer

print( dp(0) )

# 1 2 3 4 5 .... n
# 0 1 2 3 4 .... n-1
