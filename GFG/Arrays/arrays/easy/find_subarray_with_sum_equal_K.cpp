#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "Starting..."  << "\n";

    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for(size_t i=0; i<v.size(); i++) cin >> v[i];

    ll sum=v[0];
    for(size_t i=0, j=0; j<v.size();) {
        if(sum == k){
            cout << i << " " << j << "\n";
            break;
        }
        else if(sum+v[j+1] <= k) sum+= v[++j];
        else sum -= v[i++];
    }

    return (0);
}