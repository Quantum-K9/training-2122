
import sys
sys.setrecursionlimit( 100000000 )

MOD = 1000000007
# 1 <= n <= 1000000

memo = [-1]*1000002
def fib(n): #top-down dp

    #output the nth fibonacci number assuming fib(1) = 1, fib(2) = 1
    #fib(n) = fib(n-1) + fib(n-2)

    #check if we remember
    if memo[n] != -1:
        return memo[n]

    #check if it's the base case
    if n == 1 or n == 2:
        return 1

    #general case
    memo[n] = (fib(n-1) + fib(n-2))%MOD
    return memo[n]

# 1 1 2 3 5 8 13 21 34...

#print( fib(5000) ) #21


#fib(100) --> fib(99) + fib(98)
# fib(99) --> fib(98) + fib(97)

#memoization


# ==============================
# bottom-up 

answers = [ 0, 1, 1 ]

n = 1000000

for i in range( 3, n+1 ):     # for ( int i = 3; i < n+1; i++ )
    fi = answers[i-1] + answers[i-2]
    fi = fi%MOD
    answers.append( fi )

print( answers[n] )

 
