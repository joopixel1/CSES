#include <iostream>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // cout << "Starting..." << endl;

    ll n, base=5, ans=0;
    cin >> n;

    while(n >= base) {
        ans += n/base;
        base *= 5;
    }

    cout << ans;

    return (0);
}