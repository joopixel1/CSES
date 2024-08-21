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
    vector< pair<ll, ll> > v(n);
    for(size_t i=0; i<v.size(); i++) {
        cin >> a >> b;
        v[i] = make_pair(a, b);
    }
    sort(v.begin(), v.end());

    ll time=0, reward=0;
    for(auto e: v){
        time+=e.first;
        reward+=(e.second-time);
    }

    cout << reward;

    return (0);
}