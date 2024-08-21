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
    vector<ll> v(n), s(n+1);
    for(size_t i=0; i<v.size(); i++) cin >> v[i];
    s[0] = 0;
    for(size_t i=1; i<s.size(); i++) s[i] = s[i-1] + v[i-1];

    ll ans=0;
    for(ll i=1; i<=n; i++){
        for(size_t j=0+i; j<s.size(); j++){
            ll sum = s[j] - s[j-i];
            ans += (sum%n == 0);
        }
    }

    cout << ans;

    return (0);
}