
// original problem: https://codeforces.com/group/Sw3sdIlMPV/contest/266012/problem/G

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define mt make_tuple 

using namespace std;

int n,m,V;
vector<int> s;
vector< vector<pair<int,int> > > connect;

ll memo[6003][6003];

ll dp( int i, int V ){ // the maximum S you can get starting at plant i with V fuel

    if( memo[i][V] != -1 ){ return memo[i][V]; } // already explored

    ll ans = 0;

    for( int j = 0; j < connect[i].size(); j++ ){
        if ( V >= connect[i][j].second ){  // for each planet we could possibly go to
            ans = max( ans, dp( connect[i][j].first, V-connect[i][j].second) );  // explore
        }
    }

    memo[i][V] = ans+s[i]; // add value of planet i

    return memo[i][V];
}

void solve() {

    cin >> n >> m >> V;

    s.resize(n); for( int i = 0; i < n; i++ ){ cin >> s[i]; }

    for( int i = 0; i < n; i++ ){ for( int j = 0; j <= V; j++ ){ memo[i][j] = -1; } }

    connect.clear();
    connect.resize(n); 
    while( m-- ){
        int a,b,c; cin >> a >> b >> c;
        connect[a].pb( mp( b,c ) );
    }

    cout << dp(0,V) << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) { solve(); }

    return 0;
}
