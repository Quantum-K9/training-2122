#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll n,k;
ll h[100002];
ll memo[100002];

ll dp(int i){
  
	if (i == n) return 0;
	if (memo[i] != -1) return memo[i];

	ll ans = dp(i+1) + (abs(h[i]-h[i+1]));

	for (int j = 1; j <= k; j++){
		if ((i+j) > n) break;

		ans = min(ans, dp(i+j) + (abs(h[i]-h[i+j])));
	}

	memo[i] = ans;

	return ans;
}

int main(){
	cin >> n >> k;
  
	memset(memo, -1, sizeof memo);
  
	for (int i = 0; i < n; i++){ cin >> h[i]; }
  
  	n--;
  
	cout << dp(0) << endl;
	return 0;
}
