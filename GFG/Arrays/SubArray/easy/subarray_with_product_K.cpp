#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "Starting..." << "\n";

    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for(size_t i=0; i<a.size(); i++) cin >> a[i];

    size_t i, j;
    ll prod = a[0];
    for(i=0, j=1; i<a.size();){
        if(k == prod) break;

        else if (abs(prod) >= abs(k) or j == a.size()) prod/= a[i++];

        else if (a[j] == 0){
            if (k == 0) break;
            if(abs(prod) > abs(k)) prod /= a[i++];
            else {
                i=j+1;
                j++;
            }
        }

        else prod *= a[j++];
    }

    if(i>=n and j>=n) cout << "NO" << "\n";
    else cout << "YES" << "\n";

    return (0);
}