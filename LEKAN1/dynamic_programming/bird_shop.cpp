#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, x;
    cin >> n >> x;
    vector<ll> pr(n), pa(n), a(x+1);
    for(size_t i=0; i<pr.size(); i++) cin >> pr[i];
    for(size_t i=0; i<pa.size(); i++) cin >> pa[i];

    a[0] = 0;
    for(ll i=1; i<=x; i++) {
        ll maxim = 0;
        for(ll j=0; j<n; j++) {
            ll ind = i-pr[j];
            if(ind >= 0) maxim = max(maxim, pa[j] + a[ind]);
        } 
        a[i] = maxim;       
    }

    cout << a[x];

    return (0);
}