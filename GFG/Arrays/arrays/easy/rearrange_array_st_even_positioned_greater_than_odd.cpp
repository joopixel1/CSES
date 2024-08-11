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
    vector<ll> v(n), ans(n);
    for(size_t i=0; i<v.size(); i++) cin >> v[i];
    sort(v.begin(), v.end());

    for(size_t i=0; i<(v.size()+1)/2; i++) ans[i*2] = v[i];
    for(size_t i=0; i + (v.size()+1)/2 < v.size(); i++) ans[i*2 + 1] = v[i + (v.size()+1)/2];
    
    for(size_t i=0; i<v.size(); i++) cout << ans[i] << " ";

    return (0);
}