#include <iostream>
#include <vector>

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

    vector< ll > ps(n+1, 0);
    for(ll i=0; i<n; i++) ps[i+1] = ps[i] + v[i];

    ll a, b;
    for(ll i=0; i<m; i++){
        cin >> a >> b;
        cout << (ps[b+1] - ps[a]) / (b+1 - a) << "\n";
    }
    
    return (0);
}