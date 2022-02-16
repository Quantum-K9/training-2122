
// original problem: https://atcoder.jp/contests/dp/tasks/dp_d

#include <bits/stdc++.h> // includes all the necessary functions and stuff
#define ll long long

using namespace std;

vector<ll> v;
vector<int> w;
int N, W;

ll memo[102][100002]; // i, s

ll dp( int i, int s ){   // let dp(i,s) be the maximum value we can get assuming we 
						 // consider items i ... N, and we have 's' amount of space
						 // left in our knapsack

	if( memo[i][s] != -1 ){ return memo[i][s]; } // we've solved this before

	ll answer = 0;

	// base case / end case
	if( i == N ){
		if( w[i-1] <= s ){ answer = v[i-1]; }
	}

	// general case
	else{
		// we don't buy
		answer = dp( i+1, s );

		// we buy it option
		if( w[i-1] <= s ){ answer = max( answer, v[i-1] + dp(i+1, s-w[i-1]) );  }
	}

	memo[i][s] = answer; //remember

	return answer;
}

int main(){ // "main" function

	memset( memo, -1, sizeof memo );

	cin >> N >> W; // take input
	v.resize(N); // resize arrays
	w.resize(N);
	for( int i = 0; i < N; i++ ){ cin >> w[i] >> v[i]; } // for i in range(0,N)

	cout << dp( 1, W ) << endl;

	return 0;
}
