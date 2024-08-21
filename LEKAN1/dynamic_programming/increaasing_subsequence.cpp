#include <iostream>
#include <map>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // cout << "Starting..." << "\n";

    ll n, t, maxim=1;
    cin >> n;
    map<ll, ll, greater<ll>> m;
    for(ll i=0; i<n; i++){
        cin >> t;
        auto a = m.upper_bound(t);
        if(a == m.end() and !m[t]) m[t] = 1LL;
        else {
            while(a != m.end()){
                ll curr = 1LL+(*a).second;
                if(curr > m[t]) m[t] = curr, maxim = max(curr, maxim);
                a++;
            }
        }
    }
    
    cout << maxim;

    return (0);
}