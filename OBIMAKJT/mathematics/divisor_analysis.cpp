/**======================
 * ?        ABOUT
 * @author    : joopixel1
 * @createdOn : 12/18/2023
 * @details: Divisor Analysis Problem
 *========================**/
#include <iostream>

#define GIVEN_MOD 1000000007

using namespace std;

long long power (long long a, long long b);

int main(){
    int n, a, b;
    cin >> n;
    long long no_div=1, sum_div=1, num=1;

    for(; n>0; n--){
        cin >> a >> b;
        no_div *= ( b+1 )%GIVEN_MOD;
        sum_div *= ( (power(a, b+1)-1)/(a-1) )%GIVEN_MOD;
        num*= ( a*b )%GIVEN_MOD;
    }

    cout << no_div << ' ' << sum_div << ' ' << power( num, (no_div+1)/2 ) << '\n';
}

long long power (long long a, long long b){
    if(b == 0) return 1;
    
    else if(b%2 == 0) return ( power(a%GIVEN_MOD, b/2) * power(a%GIVEN_MOD, b/2) ) %GIVEN_MOD;

    else return ( power(a%GIVEN_MOD, b-1) * a ) %GIVEN_MOD;
}