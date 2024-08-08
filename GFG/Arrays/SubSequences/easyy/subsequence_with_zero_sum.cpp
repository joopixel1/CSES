#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
using ll = long long;

vector<ll> v;

// recursive approach to get all subsequences 2^n
ll countSubSequenceWithSumX(ll x, ll sum, ll i, ll cnt){
    if(i < v.size()) return countSubSequenceWithSumX(x, sum+v[i], i+1, cnt+1) + countSubSequenceWithSumX(x, sum, i+1, cnt);
    else return (cnt > 0 and sum == x) ? 1 : 0;  
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "Starting..." << "\n";

    // map way
    // ll n, t;
    // cin >> n;
    // unordered_map<ll, ll> m;
    // for(ll i=0; i<n; i++){
    //     cin >> t;
    //     m[t]++;
    //     vector<ll> p;
    //     for(auto e: m) p.push_back(e.first + t);
    //     for(auto e: p) m[e]++;
    // }

    // cout << m[0];

    // recursive way
    ll n;
    cin >> n;
    v.resize(n);
    for(size_t i=0; i<n; i++) cin >> v[i];

    cout << countSubSequenceWithSumX(0, 0, 0, 0);
    



    return (0);
}