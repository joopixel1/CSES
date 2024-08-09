#include <iostream>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
        
    ll n, t, x=0, sum=0;
    cin >> n;
    for(ll i=0; i<n; i++){
        cin >> t;
        x = t*(x+1);
        sum += x;
    }

    cout << sum;

    return (0);
}