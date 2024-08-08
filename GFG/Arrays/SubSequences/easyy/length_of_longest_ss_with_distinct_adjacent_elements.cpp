#include <iostream>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "Starting..." << "\n";

    ll n, t, p, ans=1;
    cin >> n >> p;
    for(ll i=1; i<n; i++){
        cin >> t;
        if(t != p) {
            ans++;   
            p = t; 
        }   
    } 

    cout << ans;

    return (0);
}