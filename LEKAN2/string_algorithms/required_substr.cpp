#include <iostream>

#define PRIME_MOD 1000000007


using namespace std;
using ll = long long;


ll power_mod(ll a, ll b, ll m){
    if(b <= 0) return 1;
    if(b%2) return ( a * power_mod(a, b-1, m) )%m;
    ll half = power_mod(a, b/2, m);
    return ( half * half )%m; 
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // cout << "Starting..." << "\n";

    ll n, m;
    string s;
    cin >> n >> s;
    m = s.size();
    
    ll ans = ( (n-m+1) * power_mod(26, n-m, PRIME_MOD) )%PRIME_MOD;
    cout << ans;

    return (0);
}