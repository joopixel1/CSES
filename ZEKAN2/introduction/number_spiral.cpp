#include <iostream>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // cout << "Starting..." << endl;
    
    ll n, y, x, small, large, ans;
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> y >> x;
        small = min(y, x);
        large = max(y, x);
        if(( (large&1) and (large == x) ) or ( !(large&1) and (large == y) )){
            ans = large*large;
            ans -= (small - 1);
        }
        else {
            ans = (large-1)*(large-1);
            ans += small;
        }
        cout << ans << "\n";
    }


    return (0);
}