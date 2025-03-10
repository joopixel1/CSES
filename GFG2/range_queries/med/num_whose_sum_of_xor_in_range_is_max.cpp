#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cout << "Starting..." << "\n";

    ll n, m;
    cin >> n >> m;

    vector< ll > v(n);
    for(ll i=0; i<n; i++) cin >> v[i];

    vector< vector< ll > > ps(n+1, vector<ll>(31, 0) );
    for(ll i=0; i<n; i++){ 
        for(ll j=0; j<31; j++) ps[i+1][j] = ps[i][j] + ((v[i] & (1LL << j)) != 0);
    }

    ll l, r, ans, x;
    for(ll i=0; i<m; i++){
        cin >> l >> r;
        ans = 0x7FFFFFFF;
        for(ll j=0; j<31; j++){
            x = ps[r][j] - ps[l-1][j];
            if (x >= r-l+1-x) ans ^= (1LL << j);
        }   
        cout << ans << "\n";
    }
    
    return (0);
}