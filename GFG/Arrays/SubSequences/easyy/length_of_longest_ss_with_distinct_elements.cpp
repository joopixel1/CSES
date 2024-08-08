#include <iostream>
#include <set>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "Starting..." << "\n";

    ll n;
    cin >> n;
    set<ll> s;
    for(ll i=0, t; i<n; i++) {
        cin >> t;
        s.insert(t);
    }

    cout << s.size();
 
    return (0);
}