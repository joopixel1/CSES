#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "Starting..." << "\n";

    ll n, t, c=0;
    cin >> n;
    vector<ll> v; 
    for(ll i=0; i<n; i++){
        cin >> t;
        if(t) c++;
        else {
            v.push_back(c);
            c=0;
        }
    }
    if(c != 0) v.push_back(c);

    vector<ll> s(v.size()+1);
    s[0] = 0;
    for(size_t i=1; i<s.size(); i++) s[i] = s[i-1] + v[i-1];
    
    ll ans = s[1] - s[0];
    for(size_t i=0; i<s.size()-2; i++){
        ans = max(ans, s[2+i] - s[i]);
    }

    cout << ans;

    return (0);
}
