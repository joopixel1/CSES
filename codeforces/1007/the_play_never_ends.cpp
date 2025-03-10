#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // cout << "Starting..." << "\n";

    ll n, a;
    cin >> n;
    for(ll i=0; i<n; i++){
        cin >> a;
        if (a%3  == 1) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
    
    return (0);
}