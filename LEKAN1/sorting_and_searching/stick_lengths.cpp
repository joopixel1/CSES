#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
using ll = long long;

/**----------------------------------------------
 * *                   INFO
 *   
 *   Use median for Stick lengths
 *   
 *
 *---------------------------------------------**/
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // cout << "Starting..." << "\n";

    ll n, sum=0;
    cin >> n;
    vector<ll> v(n);
    for(size_t i=0; i<v.size(); i++){
        cin >> v[i];
        sum += v[i];
    }
    sort(v.begin(), v.end());

    ll low = v[(n/2)-1];
    ll high = v[(n/2)];
    ll sum_low=0, sum_high=0;
    for(size_t i=0; i<v.size(); i++){
        sum_low += abs(v[i]-low);
        sum_high += abs(v[i]-high);
    }

    cout << min(sum_high, sum_low);
    
    return (0);
}