#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "Starting..." << "\n";

    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for(size_t i=0; i<v.size(); i++) cin >> v[i];
    sort(v.begin(), v.end());

    ll ans=0;
    auto i=v.rbegin();
    for(ll j=0; j<k; j++) ans += *(i++);
    cout << ans;

    return (0);
}