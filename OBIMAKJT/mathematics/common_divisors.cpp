/**======================
 * ?        ABOUT
 * @author    : joopixel1
 * @createdOn : 12/18/2023
 * @details: Common Divisors Problem
 *========================**/
#include <iostream>
#include <vector>

using namespace std;

int maximum=0;

static inline void gcd(int a, int b);

int main(){
    int n, a, i;
    cin >> n;
    vector<int> v;
    for(i=0; i<n; i++) {
        cin >> a;
        v.push_back(a);
    }

    int row, col;
    for(row=0; row<n; row++){
        for(col=row+1; col<n; col++) {
            gcd(v[row], v[col]);
        }
    }
    cout << maximum << '\n';
}

static inline void gcd(int a, int b){
    while(b!=0){
        if(a<=maximum || b<=maximum) return;
        int temp=b;
        b = a%b;
        a = temp;
    }
    maximum=a;
}