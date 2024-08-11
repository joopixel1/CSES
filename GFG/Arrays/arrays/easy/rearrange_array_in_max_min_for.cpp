#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "Starting..." << "\n";

    ll n, t;
    cin >> n;
    vector<ll> v(n);
    for(size_t i=0; i<v.size(); i++) cin >> v[i];
    sort(v.begin(), v.end());

    vector<ll> a;
    for(auto i=v.begin(), j=v.end()-1; i<j; i++, j--){
        if(i == j) a.push_back(*j);
        else {
            a.push_back(*j);
            a.push_back(*i);
        }
    }

    for(size_t i=0; i<a.size(); i++) cout << a[i] << " ";

    return (0);
}