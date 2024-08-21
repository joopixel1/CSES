/**======================
 * ?        ABOUT
 * @author    : joopixel1
 * @createdOn : 12/18/2023
 * @details: Counting Divisors Problem
 *========================**/
#include <iostream>

#define GIVEN_MOD 1000000007

using namespace std;

int sum_factors(int n);

int main(){
    int n;
    cin >> n;
    cout << sum_factors(n) << '\n';
}

int sum_factors(int a){
    long long e=a, p=1, i=2;
    long long h=a/i;
    long long temp = ( (e%GIVEN_MOD - h%GIVEN_MOD + GIVEN_MOD) %GIVEN_MOD * (e%GIVEN_MOD + h%GIVEN_MOD + 1)%GIVEN_MOD )%GIVEN_MOD;
    long long sum = (h==0) ? 0 : (    (temp * 500000004)%GIVEN_MOD * p%GIVEN_MOD    )%GIVEN_MOD;
    
    while( h>1 ){
        e=h;
        p=i;   
        i=a / (a/(p+1));
        h=a/i;
        temp = ( (e%GIVEN_MOD - h%GIVEN_MOD + GIVEN_MOD) %GIVEN_MOD * (e%GIVEN_MOD + h%GIVEN_MOD + 1)%GIVEN_MOD )%GIVEN_MOD;
        sum = (sum + (    (temp * 500000004)%GIVEN_MOD * p%GIVEN_MOD    )%GIVEN_MOD )%GIVEN_MOD;
    }
    
    return (sum + a%GIVEN_MOD) %GIVEN_MOD;
}