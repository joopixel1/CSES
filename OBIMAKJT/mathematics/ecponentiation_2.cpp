/**======================
 * ?        ABOUT
 * @author    : joopixel1
 * @createdOn : 12/18/2023
 * @details: Exponentiation @ problem: Problem usesidfeas from fermats theorem. Check geek for geeks if u need more explaination
 *========================**/
#include <iostream>
#include <cmath>

#define GIVEN_MOD 1000000007

using namespace std;

long long power (long long a, long long b);
long long power_modn (long long a, long long b);

int main(){
    int n;
    long long a, b, c;

    cin >> n;
    for(; n>0; n--){
        cin >> a >> b >> c; 
        cout << power( a, power_modn(b, c) ) << '\n';
    }

    return 0;
}

long long power (long long a, long long b){
    if(b == 0) return 1;
    
    else if(b & 1) return ( power(a, b-1) * a ) %GIVEN_MOD;

    else return ( power(a, b>>1) * power(a, b>>1) ) %GIVEN_MOD;
}

long long power_modn (long long a, long long b){
    if(b == 0) return 1;
    
    else if(b & 1) return ( power_modn(a, b-1) * a ) %(GIVEN_MOD-1);

    else return ( power_modn(a, b>>1) * power_modn(a, b>>1) ) %(GIVEN_MOD-1);
}