#include <iostream>

#define PRIME_MAX 1000000007

using namespace std;
using ll = long long;

ll power_mod(ll base, ll exponent, ll mod){
    ll ans = 1;
    while(exponent){
        if(exponent&1) ans = (ans * base) %mod;
        base = (base*base) %mod;
        exponent >>=1;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // cout << "Starting..." << "\n";

    ll n;
    cin >> n;

    cout << power_mod(2, n, PRIME_MAX);
 
    return (0);
}