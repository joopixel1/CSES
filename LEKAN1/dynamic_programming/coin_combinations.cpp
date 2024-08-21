#include <iostream>
#include <vector>

#define PRIME_MAX 1000000007

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, x;
    cin >> n >> x;
    vector<ll> v(n), a(x+1);
    for(size_t i=0; i<v.size(); i++) cin >> v[i];
    a[0] = 1;
    for(ll i=1; i<(x+1L); i++) {
        ll sum = 0;
        for(auto j: v) {
            if(i-j >= 0) sum = (sum + a[i-j]) %PRIME_MAX;
        } 
        a[i] = sum;       
    }

    cout << a[x];

    return (0);
}