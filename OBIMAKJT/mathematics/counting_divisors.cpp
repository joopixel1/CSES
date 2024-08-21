/**======================
 * ?        ABOUT
 * @author    : joopixel1
 * @createdOn : 12/18/2023
 * @details: Counting Divisors Problem
 *========================**/
#include <iostream>

using namespace std;

int no_factors(int n);

int main(){
    int n, a;

    cin >> n;
    for(; n>0; n--){
        cin >> a;
        cout << no_factors(a) << '\n';
    }
}

int no_factors(int a){
    int i, sum=0;
    for(i=1; i*i<=a; i++){
        if(a%i == 0){
            if(a == i*i) sum+=1;
            else sum+=2;
        }
    }
    return sum;
}