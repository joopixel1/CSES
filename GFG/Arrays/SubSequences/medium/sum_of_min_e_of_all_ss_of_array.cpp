#include <iostream>
#include <cmath>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "Starting..." << "\n";

    ll n, t, ans=0;
    cin >> n;
    while(n){
        cin >> t;
        ans += t*pow(2L, --n);
    }

    cout << ans;

    return (0);
}