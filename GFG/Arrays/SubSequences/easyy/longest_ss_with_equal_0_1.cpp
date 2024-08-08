#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "Starting..." << "\n";

    ll n, t, zero=0, one=0;
    cin >> n;
    for(ll i=0; i<n; i++) {
        cin >> t;
        if(t) one++;
        else zero++;
    }

    ll ans = min(one, zero) * 2;
    cout << ans;

    return (0);
}