#include <iostream>
#include <vector>


using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // cout << "Starting..." << "\n";

    ll n;
    cin >> n;

    vector<ll> v(n);
    for(int i=0; i<n; i++) cin >> v[i];

    ll ans=0;
    for(int i=1; i<n; i++) {
        if(v[i] < v[i-1]) {
            int diff = v[i-1] - v[i];
            v[i] += diff;
            ans += diff;
        }
    }

    cout << ans;

    return(0);
}