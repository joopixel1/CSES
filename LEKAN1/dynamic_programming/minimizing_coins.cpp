#include <iostream>
#include <vector>
#include <climits>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // cout << "Starting..." << "\n";

    ll n, x;
    cin >> n >> x;
    vector<ll> v(n), ans(x+1);
    for(size_t i=0; i<v.size(); i++) cin >> v[i];
    ans[0] = 0;
    for(ll i=1; i<=x; i++){
        ll minim=LLONG_MAX;
        for(auto a: v){
            if(i-a >= 0 and ans[i-a]!=-1) minim = (minim == -1) ? 1+ans[i-a] : min(1+ans[i-a], minim);
            else minim = (minim == LLONG_MAX) ? -1 : minim;
        }
        ans[i] = minim;
    }
    
    cout << ans[x];

    return (0);
}