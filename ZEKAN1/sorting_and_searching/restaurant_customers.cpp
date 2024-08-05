#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // cout << "Starting..." << "\n";

    ll n, a, b;
    cin >> n;

    vector<pair<ll, ll>> v;
    for(int i=0; i<n; i++){
        cin >> a >> b;
        v.push_back( make_pair(a, 1) );
        v.push_back( make_pair(b, 0) );
    }
    sort(v.begin(), v.end());

    ll count=0, maxim = 0;
    for(size_t i=0; i<v.size(); i++){
        if(v[i].second) count++;
        else count--;
        maxim = max(count, maxim);
    } 

    cout << maxim;

    return (0);
}