#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int  main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // cout << "Starting..." << "\n";

    ll n, t;
    cin >> n;
    vector< pair<ll, ll> > v(n);
    for(size_t i=0; i<v.size(); i++){
        cin >> t;
        v[i] = make_pair(t, i);
    }
    sort(v.begin(), v.end());

    ll ans = 1;
    for(size_t i=1; i<v.size(); i++) ans += (v[i].second < v[i-1].second);

    cout << ans;

    return (0);
}