#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "Starting..." << "\n";

    ll n, k, t;
    cin >> n >> k;
    unordered_map<ll, ll> m;
    unordered_set<ll> s;
    for(ll i=0; i<n; i++) {
        cin >> t;
        m[t]++;
        if(m[t] > k) s.insert(t);
    }

    for(ll a: s) cout << a << " ";

    return (0);
}

