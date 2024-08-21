#include <iostream>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // cout << "Starting..." << "\n";

    ll n;
    cin >> n;
    cout << n;
    
    while(n != 1) {
        if(n&1) n = n*3 + 1;
        else n /= 2;
        cout << " " << n;
    } 
 
    return (0);
}