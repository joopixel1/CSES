#include <iostream>
#include <set>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // cout << "Starting..." << endl;

    ll n, m, a;
    cin >> n >> m;

    multiset<ll> h;
    for(int i=0; i<n; i++) {
        cin >> a;
        h.insert(a);
    }

    for(int i=0; i<m; i++) {
        cin >> a;
        auto point = h.upper_bound(a);

        if(point == h.begin()) point = h.end();
        else point--;
        
        if(point == h.end()) cout << -1 << endl;
        else {
            cout << *point << endl;
            h.erase(point);
        }
    }





    return (0);
}