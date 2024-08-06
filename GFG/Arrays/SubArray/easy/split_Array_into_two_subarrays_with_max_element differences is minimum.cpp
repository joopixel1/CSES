#include <iostream>
#include <vector>
#include <algorithm>

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
    
    sort(a.begin(), a.end());
    ll ans = a[1] - a[0];
    for(size_t i=2; i<a.size(); i++) ans = min(ans, a[i]-a[i-1]);

    cout << ans;

    return (0);
}