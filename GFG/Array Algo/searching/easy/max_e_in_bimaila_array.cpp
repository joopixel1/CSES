#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

vector<ll> v;

ll modified_search(ll i, ll j){
    ll mid = (i+j)/2;
    if(v[mid-1] < v[mid] and v[mid] > v[mid+1]) return mid;
    else if(v[mid-1] < v[mid] and v[mid] < v[mid+1]) {
        if(mid+1 >= j) return j;
        else return modified_search(mid+1, j);
    }
    else{
        if(mid-1 <= i) return i;
        else return modified_search(i, mid-1);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "Starting..." << "\n";

    ll n;
    cin >> n ;
    v.resize(n);
    for(size_t i=0; i<v.size(); i++) cin >> v[i];

    cout << v[modified_search(0, v.size()-1)];

    return (0);
}

