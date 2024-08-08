#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "Starting..." << "\n";

    ll n, t, m, ans=0;
    cin >> n >> t;
    m = t;
    if(t>0) ans += t;
    
    for(ll i=1; i<n; i++){
        cin >> t;
        if(t>0) ans += t;
        m = max(m, t);
    } 

    if(m < 0) ans = m;
    cout << ans;

    return (0);
}