#include <string>
#include <iostream>
#include <array>

#define MAXN 1000000
#define MOD 1000000007

using namespace std;
using ll = long long;

array<ll, MAXN+1> fact;
array<ll, MAXN+1> inv;
array<int, 26> alph = {};

ll mod_power(ll a, ll b, ll m){
    ll ans = 1;
    while(b>0){
        if(b&1) ans = (ans * a) %m;
        b /= 2;
        a = (a*a) %m;
    }
    return ans;
}

int main(){
    fact[0] = fact[1] = inv[0] = inv[1] = 1;
    for(int i=2; i <= MAXN; i++){
        fact[i] =(fact[i-1]*i) %MOD;
        inv[i] = mod_power(fact[i], MOD-2, MOD);
    }

    string s;
    cin >> s;
    for(char c: s) alph[c-'a']++;

    ll ans = fact[s.size()];
    for(int i: alph) ans = (ans * inv[i]) %MOD;
    cout << ans << '\n';
}