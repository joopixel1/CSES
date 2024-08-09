#include <iostream>
#include <set>
#include <cmath>
#include <vector>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "Starting..." << "\n";

    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for(size_t i=0; i<v.size(); i++) cin >> v[i];
    multiset<ll> m;

    for(ll i=0; i<k; i++){
        m.insert(v[i]);
    }
    cout << abs(*m.begin() - *m.rbegin()) << "\n";

    for(ll i=1; i<n-k+1; i++){
        m.erase(v[i-1]);
        m.insert(v[i+k-1]);
        cout << abs(*m.begin() - *m.rbegin()) << "\n";
    }    

    return (0);
}


