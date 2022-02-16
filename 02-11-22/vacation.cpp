#include <bits/stdc++.h> // includes all the necessary functions and stuff
#define ll long long // shortcut for easier coding

using namespace std;  // another shortcut

// pre = 1: swimming     -->  A
// pre = 2: bug catching -->  B
// pre = 3: homework     -->  C

ll memo[ 100003 ][ 4 ]; //[ [ 1, 2, 3 ], [ 4, 5, 6 ] ] // set up memo table

vector<ll> A, B, C;
int N;

ll dp( int i, int pre ){ // let dp(i,pre) be the maximum happiness we can get
						 // from days i ... N, assuming we did activity 'pre'
						 // the previous day

	if ( memo[i][pre] != -1 ){ //we've solved for this before
		return memo[i][pre];
	}

	ll answer = 0;

	// base case (corner case), (end case)
	if( i == N ){
		if( pre != 1 ){ answer = max( answer, A[i-1] ); }
		if( pre != 2 ){ answer = max( answer, B[i-1] ); }
		if( pre != 3 ){ answer = max( answer, C[i-1] ); }
	}

	// general case
	else{
		if( pre != 1 ){ answer = max( answer, A[i-1] + dp( i+1, 1) ); }
		if( pre != 2 ){ answer = max( answer, B[i-1] + dp( i+1, 2) ); }
		if( pre != 3 ){ answer = max( answer, C[i-1] + dp( i+1, 3) ); }
	}

	memo[i][pre] = answer; // to "remember"

	return answer;
}

int main(){ // "main" function

	memset( memo, -1, sizeof memo ); // fills memo with -1: default value
	
	cin >> N; // take input
	A.resize(N); // resize arrays
	B.resize(N);
	C.resize(N);
	for( int i = 0; i < N; i++ ){ cin >> A[i] >> B[i] >> C[i]; } // for i in range(0,N)

	cout << dp( 1, 0 ) << endl; // '\n'

	return 0;
}
