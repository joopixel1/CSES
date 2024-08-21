#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // cout << "Starting..." << "\n";

    ll n;
    cin >> n;
    vector<ll> v(n), s(n);
    for(size_t i=0; i<v.size(); i++) cin >> v[i];
    s[0] = v[0];
    for(size_t i=1; i<s.size(); i++) s[i] = v[i] + s[i-1];

    ll ans=0;
    auto maxim = max_element(s.begin(), s.end());
    if(*maxim < 0){
        auto m = max_element(v.begin(), v.end());
        ans = *m;
    }
    else{
        auto minim = min_element(s.begin(), maxim);
        if(*minim > 0) ans = *maxim;
        else ans = *maxim - *minim;
    }   

    cout << ans;

    return (0);
}