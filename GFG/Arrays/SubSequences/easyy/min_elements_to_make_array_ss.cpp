#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

vector<ll> l_n;
vector<ll> l_m;

ll length_longest_equal_subsequence(){
	vector< vector<ll> > dp(l_n.size()+1, vector<ll>(l_m.size()+1));
	ll temp;

	for(size_t i=0; i<=l_n.size(); i++) {
		for(size_t j=0; j<=l_m.size(); j++) {
			if(i==0 or j==0) temp =0;
			else if(l_n[i] == l_m[j]) temp = 1 + dp[i-1][j-1];
			else temp = max(dp[i-1][j], dp[i][j-1]);
			
			dp[i][j] = temp;
		}
	}

	return dp[l_n.size()][l_m.size()];
}

int mian(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cout << "Starting..." << "\n";

	ll n, m;
	cin >> n >> m;
	l_n.resize(n);
	l_m.resize(m);
	for(size_t i=0; i<l_n.size(); i++) cin >> l_n[i];
	for(size_t i=0; i<l_m.size(); i++) cin >> l_m[i];

	cout << l_n.size() - length_longest_equal_subsequence();

	return (0);
}