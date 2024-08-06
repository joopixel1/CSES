#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "Starting..." << "\n";

    ll n; 
    cin >> n;
    
    vector<ll> a(n);
    for(size_t i=0; i<a.size(); i++) cin >> a[i];

    size_t m=1;
    for(size_t l=0, r=0; r<a.size()-1;){
        if((a[r] xor a[r+1]) & 1) m = max(m, (++r)-l+1);
        else l = (++r);
    }

    cout << m;

    return (0);
}