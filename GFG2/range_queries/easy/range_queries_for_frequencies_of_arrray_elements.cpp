#include <iostream>
#include <vector>
#include <unordered_map>

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

    unordered_map< ll, vector< ll > > u;
    for(ll i=0; i<n; i++) u[v[i]].push_back(i);

    ll l, r, x;
    for(ll i=0; i<m; i++){
        cin >> l >> r >> x;
        cout << upper_bound(u[x].begin(), u[x].end(), r) - lower_bound(u[x].begin(), u[x].end(), l) << "\n";
    }
    
    return (0);
}