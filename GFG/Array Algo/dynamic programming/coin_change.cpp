#include <iostream>
#include <vector>
#include <set>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "Starting..." << "\n";

    ll n, k;
    cin >> n >> k;
    vector<ll> c(n);
    for(size_t i=0; i<n; i++) cin >> c[i];

    vector< vector<ll> > v(n+1, vector<ll>(k+1, 0));
    v[0][0] = 1;
    for(size_t i=1; i<v.size(); i++){
        ll coin = c[i-1];
        for(size_t j=0; j<v[i].size(); j++){
            ll z = j-coin;
            v[i][j] += v[i-1][j];
            if(z >= 0) v[i][j] += v[i][z];
        }
    }

    cout << v[n][k];

    return (0);
}