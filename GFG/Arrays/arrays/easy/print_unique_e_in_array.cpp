#include <iostream>
#include <set>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "Starting..."  << "\n";

    ll n, t;
    cin >> n;
    set<ll> s;
    for(ll i=0; i<n; i++){
        cin >> t;
        s.insert(t);
    }
     
    for(auto a: s) cout << a << " ";

    return (0);
}