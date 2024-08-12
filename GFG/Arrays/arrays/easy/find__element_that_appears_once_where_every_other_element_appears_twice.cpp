#include <iostream>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "Starting..."  << "\n";

    ll n, t, ans=0;
    cin >> n;
    for(ll i=0; i<n; i++){
        cin >> t;
        ans ^= t;
    }
     
    cout << ans;

    return (0);
}