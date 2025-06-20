#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;

    vector< ll > v(n);
    for(ll i=0; i<n; i++) cin >> v[i];

    vector< ll > b;
    for(auto i: v){
        for(auto e: b){
            i = min(i, i^e);
        }
        if (i) b.push_back(i);
    }

    cout << (1LL <<  b.size()) << "\n";

    return 0;
}
