#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "Starting..." << "\n";

    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for(size_t i=0; i<v.size(); i++) cin >> v[i];
    sort(v.begin(), v.end());

    // greedy algorithm
    ll i=0, j=1;
    while(j<k){
        if(v[i]>j){
            v.insert(lower_bound(v.begin(), v.end(), j), j);
            j+=j;
        }
        else{
            j+= v[i];
            i++;
        }
    }

    cout << v.size() - n;
    
    return (0);
}