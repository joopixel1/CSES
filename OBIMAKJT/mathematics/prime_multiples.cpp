/**======================
 * ?        ABOUT
 * @author    : joopixel1
 * @createdOn : 12/18/2023
 * @details: Prime Multiples Problem
 *========================**/
#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, a, i;
    vector<int> v;
    cin >> n;
    
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