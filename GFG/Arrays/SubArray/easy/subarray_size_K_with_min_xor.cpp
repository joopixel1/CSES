#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "Starting..." << "\n";

    ll n, k, m=0, x=0; 
    cin >> n >> k;
    
    vector<ll> a(n);
    for(size_t i=0; i<a.size(); i++) cin >> a[i];

    for(ll i=0; i<k; i++) m = m xor a[i];
    x = m;

    for(size_t i=1; i<a.size()-k+1; i++){
        x = x xor a[i-1] xor a[i+k-1];
        m = min(x, m);
    }

    cout << m;

    return (0);
}