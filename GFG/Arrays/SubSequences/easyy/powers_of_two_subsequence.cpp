#include <iostream>
#include <cmath>

using namespace std;
using ll = long long;

ll countSubSequence(ll a){
    return pow(2L, a) - 1;
}

bool isPowerTwo(ll a){
    if(a < 1) return false;
    return (a&(a-1)) == 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "Starting..." << "\n";

    ll n, t, ans=0;
    cin >> n;
    for(ll i=0; i<n; i++) {
        cin >> t;
        if(isPowerTwo(t)) ans++;
    }

    ans = countSubSequence(ans);
    cout << ans;

    return (0);
}