#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "Starting..." << "\n";

    ll n, k;
    cin >> n >> k;
    vector<ll> p(n), w(n);
    for(size_t i=0; i<p.size(); i++) cin >> p[i];
    for(size_t i=0; i<w.size(); i++) cin >> w[i];

    vector< vector<ll> > dp(k, vector<ll>(n, 0));
    for(size_t i=0; i<dp.size(); i++){
        for(size_t j=0; j<dp[0].size(); j++){
            ll w_j = w[j];
            if(w_j <= i+1) dp[i][j] += p[j];
            ll z = i-w_j;
            if(z >= 0 and j>0) dp[i][j] += dp[z][j-1];
            if(j>0) dp[i][j] = max(dp[i][j], dp[i][j-1]);
        }
    }

    cout << dp[k-1][n-1];

    return (0);
}