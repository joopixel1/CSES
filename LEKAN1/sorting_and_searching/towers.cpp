#include <iostream>
#include <set>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // cout << "Starting..." << "\n";

    ll n, k;
    cin >> n;

    multiset<ll> t;
    for(int i=0; i<n; i++) {
        cin >> k;
        auto p = t.upper_bound(k);
        
        if(p != t.end()) t.erase(p);
        t.insert(k);
    }

    cout << t.size() << "\n";

    return (0);
}