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

vector<ll> closest(ll x, ll k){
    sort(v.begin(), v.end());
    vector<ll> arr(k);

    ll ind = search(x, 0, v.size()-1);
    size_t i=0;
    if(v[ind] != x) arr[i++] = v[ind]; 
    for(size_t a=ind-1, b=ind+1; i<k; i++){
        if(a<0) arr[i] = v[b++];
        else if(b>=v.size()) arr[i] = v[a--];
        else if(abs(v[a] - x) < abs(v[b] - x)) arr[i] = v[a--];
        else arr[i] = v[b++];
    }

    return arr;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "Starting..." << "\n";

    ll n, x, k;
    cin >> n >> x >> k;
    v.resize(n);
    for(size_t i=0; i<v.size(); i++) cin >> v[i];

    vector<ll> a = closest(x, k);

    for(auto i: a) cout << i << " ";

    return (0);
}

