#include <iostream>
#include <vector>
#include <climits>

using namespace std;
using ll = long long;

constexpr ll LL_SIZE = CHAR_BIT * sizeof(ll);

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;

    vector< ll > v(n);
    for(ll i=0; i<n; i++) cin >> v[i];

    ll idx = 0;
    for(ll i=LL_SIZE-1; i>=0; i--){
        ll mask = (1LL << i);

        // find maxInd and maxEle
        ll maxIdx = idx, maxEle = LLONG_MIN;
        for(ll j=idx; j<(ll)v.size(); j++){
            if(v[j] & mask and v[j] > maxEle){
                maxEle = v[j];
                maxIdx = j;
            }
        }

        if(maxEle == LLONG_MIN) continue;

        // remove maxEle from other elements
        for(ll j=0; j<(ll)v.size(); j++){
            if(v[j] & mask and j != maxIdx) v[j] ^= maxEle;
        }
        
        swap(v[idx], v[maxIdx]);
        idx++;
    }

    // get andswer by xor alterd array
    ll ans = 0;
    for(auto e: v) ans^= e;

    // print answer
    cout << ans;

    return 0;
}
