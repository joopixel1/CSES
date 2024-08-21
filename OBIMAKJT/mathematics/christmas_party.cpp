/**======================
 * ?        ABOUT
 * @author    : joopixel1
 * @createdOn : 12/20/2023
 * @details   : Christmas Party Problem
 *========================**/
#include <iostream>
#include <array>

#define MOD 1000000007
#define MAXN 1000000

using namespace std;
using ll = long long;

array<ll, MAXN+1> fac;
array<ll, MAXN+1> inv;

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
    for (ll i=2; i<=MAXN; i++){
        fac[i] = (fac[i-1]*i) %MOD;
        inv[i] = mod_power(fac[i], MOD-2, MOD); // fermats little theorem
    }

    ll n, ans=0;
    cin >> n;
    
    // christmas party n = n! nEi=0 1/i!
    for (ll i=0; i<=n; i++) {
        if(i & 1) ans = (ans + MOD - inv[i]) %MOD;
        else ans = (ans + inv[i]) %MOD; 
    }
    ans = (ans * fac[n]) %MOD;

   cout << ans;
    return 0;
}