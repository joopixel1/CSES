#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // cout << "Starting..." << "\n";

    string n;
    ll maxim, cur=0;
    char l = n[0];
    for(char a: n){
        if(a == l) {
            cur++;            
        }
        else {
            maxim = max(maxim, cur);
            cur = 0;
        }
    }
    
    maxim = max(maxim, cur);
    cout << maxim;
 
    return (0);
}