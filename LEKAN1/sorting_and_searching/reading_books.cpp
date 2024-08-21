#include <iostream>
#include <set>

using namespace std;
using ll = long long;

/**
 * greedy approach:
 * answer is the max of the sum of the elements or twice the largest element
 */
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // cout << "Starting..." << "\n";

    ll n, t, maxim=0, sum=0;
    cin >> n;
    for(ll i=0; i<n; i++){
        cin >> t;
        maxim = max(t, maxim);
        sum += t;
    }

    cout << max(maxim*2, sum);

    return (0);
}