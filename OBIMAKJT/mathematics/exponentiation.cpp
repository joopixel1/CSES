/**======================
 * ?        ABOUT
 * @author    : joopixel1
 * @createdOn : 12/18/2023
 * @details: Exponentiation problem
 *========================**/
#include <iostream>
#include <cmath>

#define GIVEN_MOD 1000000007

using namespace std;

long long power (long long a, long long b);

int main(){
    int n;
    long long a, b;

    cin >> n;
    for(; n>0; n--){
        cin >> a >> b;
        cout << ((long long) power(a%GIVEN_MOD, b)) % GIVEN_MOD << '\n';
    }
}

long long power (long long a, long long b){
    if(b == 0) return 1;
    
    else if(b%2 == 0) return ( power(a%GIVEN_MOD, b/2) * power(a%GIVEN_MOD, b/2) ) %GIVEN_MOD;

    else return ( power(a%GIVEN_MOD, b-1) * a ) %GIVEN_MOD;
}