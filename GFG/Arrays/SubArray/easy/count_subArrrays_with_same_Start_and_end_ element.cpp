#include <iostream>
#include <map>

using namespace std;
using ll = long long;

ll countSubArray(ll a){
    return (a*(a+1))/2;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "Starting..." << "\n";

    ll n, t, ans=0;
    cin >> n;
    map<ll, ll> m;
    for(ll i=0; i<n; i++){
        cin >> t;
        if (m.count(t)) m[t]++;
        else m[t] = 1;
    }

    for(auto i: m){
        ans += countSubArray(i.second);
    }

    cout << ans;

    return (0);
}