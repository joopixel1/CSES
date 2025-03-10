#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

void create_sequence(vector< ll >& _v, ll r){
    ll n = 0, sum=0;
    while(_v.size() < r) {
        ll m = (_v.size() + 1) / 2;
        if (m == n) _v.push_back(sum);
        else {
            while(m < n) sum ^= ++n;
            _v.push_back(sum);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // cout << "Starting..." << "\n";

    ll t, n, l, r;
    cin >> t;

    for(ll x=0; x<t; x++){
        cin >> n >> l >> r;
        vector< ll > v(n);
        for(ll i=0; i<n; i++) cin >> v[i];

        create_sequence(v, r);
        cout << v[r-1];
    }
    
    return (0);
}