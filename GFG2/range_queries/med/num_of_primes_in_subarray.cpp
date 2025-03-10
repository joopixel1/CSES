#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef long long ll;

void sieve_of_eratosthenes(vector< ll > _e){
    if(_e.size() > 0) _e[0] = 0;
    if(_e.size() > 1) _e[1] = 0;

    for(ll i=0; i<_e.size(); i++){
        if(_e[i]){
            for(ll j=i*i; j<_e.size(); j+=i) _e[j] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cout << "Starting..." << "\n";

    vector< ll > e(10000, 1);
    sieve_of_eratosthenes(e);
    set < ll > p;
    for(ll i=0; i<e.size(); i++) {
        if(e[i]) p.insert(i);
    }

    ll n, m, t;
    cin >> n >> m;

    vector< ll > v(n);
    for(ll i=0; i<n; i++) {
        cin >> t;
        v[i] = p.count(t) > 0;
    }

    vector< ll > ps(n+1, 0);
    for(ll i=0; i<n; i++) ps[i+1] = ps[i] + v[i];

    ll a, b;
    for(ll i=0; i<m; i++){
        cin >> a >> b;
        cout << ps[b+1] - ps[a] << "\n";
    }
    
    return (0);
}