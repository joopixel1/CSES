#include <iostream>
#include <vector>

using  namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, l, r;
    cin >> n >> l >> r;
    vector<ll> v(n);
    for(size_t i=0; i<v.size(); i++) cin >> v[i];

    bool ans = false;
    for(ll i=l-1; i>=0 and !ans; i--) {
        if(v[i] == v[l]) ans = true;
    }
    
    for(ll i=r+1; i<n and !ans; i++) {
        if(v[i] == v[r]) ans = true;
    }

    if(ans) cout << "YES";
    else cout << "NO";

    return (0);
}