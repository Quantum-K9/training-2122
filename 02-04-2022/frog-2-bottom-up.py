
#original problem: https://atcoder.jp/contests/dp/tasks/dp_b

n,k = [ int(x) for x in input().split() ]
h = [ int(x) for x in input().split() ]

memo = [-1]*(n+1)

# memo[i] is the cheapest way to get from stone i to stone n --> dp(1)

memo[n-1] = 0 #adjust since we're using 0-based indexing

for i in range( n-2, -1, -1 ): #loop instead of recursion
    
    answer = abs(h[i]-h[i+1]) + memo[i+1] #base value
    
    for stepSize in range(2, k+1):

        if i+stepSize > n-1:
            break
    
        answer = min( answer, abs( h[i]-h[i+stepSize] ) + memo[ i + stepSize ] )

    memo[i] = answer

print( memo[0] )
    
