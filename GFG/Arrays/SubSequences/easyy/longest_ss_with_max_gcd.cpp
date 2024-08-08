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
    multiset<ll> m;
    for(ll i=0, t; i<n; i++) {
        cin >> t;
        m.insert(t);
    }
    
    cout << m.count(*m.rbegin());

    return (0);
}