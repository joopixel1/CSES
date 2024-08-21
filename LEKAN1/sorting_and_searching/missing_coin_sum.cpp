#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // cout << "Starting..." << "\n";

    ll n;
    cin >> n;
    vector<ll> v(n);
    for(size_t i=0; i<v.size(); i++) cin >> v[i];
    sort(v.begin(), v.end());

    ll curr=1; 
    for(size_t i=0; i<v.size(); i++){
        if(curr < v[i]) break;
        else curr += v[i];
    }

    cout << curr;


    return (0);
}