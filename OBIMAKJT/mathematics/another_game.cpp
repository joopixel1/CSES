/**======================
 * ?        ABOUT
 * @author    : joopixel1
 * @createdOn : 2/7/2024
 * @details: Another Game Problem
 *========================**/
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main(){
    int t, n, x, m, count=1;
    cin >> t;

    for(int i=0; i<t; i++){
        cin >> n >> m;
        for(int j=1; j<n; j++){
            cin >> x;
            if(x > m){
                m = x;
                count=1;
            }
            else if (x == m){
                count++;
            }
        }
        if (m&1) {
            if (count == 1) cout << "first" << "\n";
            else cout << "second" << "\n";
        }
        else {
            if (count == 1) cout << "second" << "\n";
            else cout << "first" << "\n";
        }
    }
}
