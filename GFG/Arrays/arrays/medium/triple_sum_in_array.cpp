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

    for(size_t a=0; a<v.size(); a++){
        ll p = k - v[a];
        for(size_t i=0, j=v.size()-1; i<j;){
            ll sum = v[i] + v[j];
            if(sum == p) {
                cout << v[a] << " " << v[i] << " " << v[j];
                return (0);
            }
            else if(sum > p) j--;
            else i++;
        }
    }

    return (0);
}