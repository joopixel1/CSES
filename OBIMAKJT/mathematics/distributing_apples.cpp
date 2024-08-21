#include <iostream>
#include <array>

#define MOD 1000000007
#define MAXN 1000000

using namespace std;
using ll = long long;

array<ll, MAXN*2+1> fac;
array<ll, MAXN*2+1> inv;

ll comb(ll start, ll end){
    ll ans = fac[start];
    ans = (ans * inv[end]) %MOD;
    ans = (ans * inv[start-end]) %MOD;
    return ans;
}

// (a^b) mod m -- binary method O(log n)
ll mod_power(ll a, ll b, ll mod){
    ll ans=1;
    while(b>0){
        if(b&1) ans = (ans*a) %mod;
        b /= 2;
        a = (a*a) %mod;
    }
    return ans;
}

int main(){
    fac[0] = fac[1] = inv[0] = inv[1] = 1;
    for (int i=2; i<=MAXN*2; i++){
        fac[i] = (fac[i-1]*i) %MOD;
        inv[i] = mod_power(fac[i], MOD-2, MOD); // fermats little theorem
    }

    ll n, m;
    cin >> n >> m;
    cout << comb(n+m-1, n-1) << '\n';
}