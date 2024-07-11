#include <iostream>
#include <vector>

#define MAX_PRIME 1000000007
#define SIZE 100000000

using namespace std;
using ll = long long;


/**----------------------------------------------
 * *                   INFO - HOW TO CALCULATE MOD POWER O(logn)
 * NO SPECIAL NUMBER THEOREM ALGORITHM.
 * Its pretty simple when you think of it you just have to think of the exponent as a base 2 number.
 * 
 *---------------------------------------------**/
ll power_mod(ll base, ll exponent, ll mod){
    ll ans = 1;
    while(exponent){
        if(exponent&1) ans = (ans * base) %mod;
        base = (base*base) %mod;
        exponent >>=1;
    }
    return ans;
}

ll combinationToBaseTwo(ll a, ll invTwo){
    return ( ((a * (a-1)) %MAX_PRIME) * invTwo ) %MAX_PRIME;
}

ll triangle(ll a){
    return ( a*(a+1) ) /2;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // cout << "Starting..." << endl;

    ll n, comb, pos, invTwo = power_mod(2, MAX_PRIME-2, MAX_PRIME);
    cin >> n;

    for(ll i=1; i<=n; i++) {
        comb = combinationToBaseTwo(i*i, invTwo);
        pos = 8*triangle(i-2);
        cout << comb - pos << "\n";
    }

    return (0);
}