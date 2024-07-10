#include <iostream>

#define MAX_PRIME 7
#define SIZE 100000000

using namespace std;
using ll = long long;

ll fact[SIZE+1];
ll inv[SIZE+1];

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

/**----------------------------------------------
 * *                        INFO 
 * The `initializeFactorialsAndInverses` function computes and initializes
 * arrays `fact[]` and `inv[]` for factorial values and their modular inverses
 * modulo `MAX_PRIME`. It leverages the following mathematical principles:
 * 
 * - **Factorials**: `fact[i] = i! % MAX_PRIME`. Factorials are computed iteratively
 *   using the relation `fact[i] = i * fact[i-1] % MAX_PRIME`.
 * 
 * - **Modular Inverses**: `inv[i]` is the modular inverse of `fact[i]` modulo `MAX_PRIME`.
 *   - Uses Fermat's Little Theorem for prime `MAX_PRIME`: If `p` is prime, then `a^(p-1) ≡ 1 (mod p)`.
 *   - Computing `inv[i]` as `power_mod(fact[i], MAX_PRIME - 2)` efficiently finds the modular inverse.
 *   - After computing `inv[SIZE-1]`, the function loops backwards from `SIZE-2` to `1` to compute
 *     `inv[i] = (i+1) * inv[i+1] % MAX_PRIME`. This ensures that all modular inverses up to `SIZE-1`
 *     are computed using previously computed values, leveraging efficiency and precomputed factorials.
 *
 *
 * The function ensures efficient computation of factorials and their inverses, essential
 * for combinatorial calculations such as binomial coefficients (`C(n, k)`) modulo a prime.
 *
 *---------------------------------------------**/
void initializeFactorialsAndInverses(){
    fact[0] = inv[0] = fact[1] = inv[1] = 1;
    // for(ll i=2; i<=SIZE; i++) fact[i] = (i*fact[i-1]) %MAX_PRIME;
    // inv[SIZE] = power_mod(fact[SIZE], MAX_PRIME-2, MAX_PRIME);
    // for(ll i=SIZE-1; i>1; i--) inv[i] = ((i+1)*inv[i+1]) %MAX_PRIME;'
    for(int i=2; i <= SIZE; i++){
        fact[i] = (i*fact[i-1]) %MAX_PRIME;
        inv[i] = power_mod(fact[i], MAX_PRIME-2, MAX_PRIME);
    }    
}

ll combination(ll a, ll b){
    return ( ((inv[a] * inv[a-b]) %MAX_PRIME ) * fact[a]) %MAX_PRIME; 
}

ll triangle(ll a){
    return (a*a+1)/2;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "Starting..." << endl;

    initializeFactorialsAndInverses();

    ll n;
    cin >> n;

    for(ll i=1; i<=n; i++) cout << combination(i*i, 2) - 8*triangle(i-1) << "\n";

    return (0);
}