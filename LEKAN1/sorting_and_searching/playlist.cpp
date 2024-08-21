#include <iostream>
#include <unordered_map>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // cout << "Starting..." << "\n";

    ll n, t, maxim=0, curr=0;
    cin >> n;
    unordered_map<ll, ll> m;
    for(ll i=1; i<=n; i++) {
        cin >> t;
        if(m[t]) curr = i-m[t];
        else maxim = max(maxim, ++curr);
        m[t] = i;
    }

    cout << maxim;

    return (0);
}