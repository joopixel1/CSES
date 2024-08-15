#include <iostream>
#include <set>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "Starting..." << "\n";

    ll n, v, t;
    cin >> n >> v;
    set<ll> s;
    for(ll i=0; i<n; i++){
        cin >> t;
        s.insert(t);
    }

    ll ans=0;
    while (v!=0){
        v -= *(--s.upper_bound(v));
        ans++;
    }

    cout << ans;
    


    return (0);
}