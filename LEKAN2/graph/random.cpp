/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>

#define PRIME_MOD 1000000007

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    vector<ll> digits(20001, 0), answers(20001, 0);
    for(ll i=1; i<=20000; i++) digits[i] = (digits[i/10] + (i%10)) %PRIME_MOD;
    for(ll i=1; i<=20000; i++) answers[i] = (answers[i-1] + digits[i]) %PRIME_MOD;
    
    ll n, a;
    cin >> n;
    for(ll i=1; i<=n; i++){
        cin >> a;
        cout << answers[a] << "\n";
    }

    return 0;
}