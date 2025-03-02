#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

void seive_of_eratosthenes(vector< ll >& _e){
    _e[0] = 0;
    _e[1] = 0;

    for(ll i=0; i<_e.size(); i++){
        if(_e[i]){
            for(ll j = i*i; j<_e.size(); j+=i) _e[j] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cout << "Starting..." << "\n";

    vector< ll > e(10000, 1), ps(10001, 0);
    seive_of_eratosthenes(e);
    for(ll i=0; i<10000; i++) ps[i+1] = ps[i] + e[i];

    ll m, l, r;
    cin >> m;
    for(ll i=0; i<m; i++){
        cin >> l >> r;
        cout << ps[r+1] - ps[l] << "\n";
    }
    
    return (0);
}