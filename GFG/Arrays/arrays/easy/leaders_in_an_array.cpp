#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "Starting..."  << "\n";

    ll n;
    cin >> n;
    vector<ll> v(n);
    for(size_t i=0; i<v.size(); i++) cin >> v[i];

    ll maxim = *v.rbegin() - 1;
    for(auto i=v.rbegin(); i!=v.rend(); i++) {
        if(*i > maxim){
            maxim = *i;
            cout << *i << " ";
        }
    }

    return (0);
}