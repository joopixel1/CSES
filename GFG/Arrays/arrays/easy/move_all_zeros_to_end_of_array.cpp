#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "Starting..."  << "\n";

    ll n, t;
    cin >> n;
    vector<ll> v(n, 0);
    for(ll i=0, j=0; i<n; i++){
        cin >> t;
        if(t) v[j++] = t;
    }
     
    for(size_t i=0; i<v.size(); i++) cout << v[i] << " ";

    return (0);
}