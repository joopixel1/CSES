#include <iostream>
#include <array>
#include <vector>

#define MOD 1000000007
#define MAX 1000000

using namespace std;
using ll = long long;

array<ll, MAX+1> fact;
array<ll, MAX+1> inv;

ll pow_binary(ll a, ll b, ll m){
    ll ans = 1;
    while (b > 0){
        if(b&1) ans = (ans * a) %m;
        b /= 2;
        a = (a * a) %m;
    }
    return ans;
}

int main () {
    fact[0] = fact[1] = inv[0] = inv[1] = 1;
    for (int i=2; i<=MAX+1; i++){
        fact[i] = (i*fact[i-1]) %MOD;
        inv[i] = pow_binary(fact[i], MOD-2, MOD);
    }

    int n, a, b;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> a >> b;
        cout << ( ((fact[a] * inv[b]) %MOD) * inv[a-b] ) %MOD << '\n';
    }
}

