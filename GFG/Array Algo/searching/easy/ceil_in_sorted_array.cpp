#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

vector<ll> v;

ll search(ll a, ll i, ll j){
    ll mid = (i+j)/2;
    if(v[mid] == a) return mid;
    else if(a < v[mid]) {
        if(mid-1 <= i) return i;
        else return search(a, i, mid-1);
    }
    else{
        if(mid+1 >= j) return j;
        else return search(a, mid+1, j);
    }
}

ll ceiling(ll a){
    sort(v.begin(), v.end());
    if(a > v.back()) return -1;
    if(a < v.front()) return 0;

    ll ind = search(a, 0, v.size()-1);
    while(ind>0 and v[ind-1] >= a) ind--;
    while(ind<v.size() and v[ind] < a) ind++;

    return ind;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "Starting..." << "\n";

    ll n, k;
    cin >> n >> k;
    v.resize(n);
    for(size_t i=0; i<v.size(); i++) cin >> v[i];

    cout << ceiling(k);

    return (0);
}

