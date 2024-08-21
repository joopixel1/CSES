#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // cout << "Starting..." << "\n";

    ll n, x;
    cin >> n >> x;
    vector<ll> v(n), s(n+1);
    for(size_t i=0; i<v.size(); i++) cin >> v[i];

    ll m = abs( *min_element(v.begin(), v.end()) ) +1;
    for(size_t i=0; i<v.size(); i++) v[i] += m;
    
    s[0] = 0;
    for(size_t i=1; i<s.size(); i++) s[i] = s[i-1] + v[i-1];

    ll ans = 0;
    for(auto i=s.begin(), j=s.begin()+1; j!=s.end();){
        ll sum = *j - *i;
        if(sum == x) ans++, j++;
        else if(sum < x) j++;
        else i++;
    }

    cout << ans;

    return (0);
}