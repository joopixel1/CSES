#include <iostream>

using namespace std;
using ll = long long;

int main(){
    ios:: sync_with_stdio(0);
    cin.tie(0);

    // cout << "Starting..." << endl;

    ll n;
    cin >> n;

    if (n == 1) cout << "1";
    else if (n <= 3) cout << "NO SOLUTION";
    else {
        for(int i=1; i<=n/2; i++){
            cout << i+n/2 << " ";
            cout << i << " ";
        }
        if(n&1) cout << n;
    }

    return (0);
}