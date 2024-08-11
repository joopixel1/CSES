#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>


using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "Starting..." << "\n";

    ll n;
    cin >> n;
    vector<ll> v(n);
    for(size_t i=0; i<v.size(); i++) cin >> v[i];
    
    map<char, ll> m;
    for(size_t i=0; i<v.size(); i++) {
        string s = to_string(v[i]);
        set<char> t;
        for(auto c: s) t.insert(c);
        for(auto l: t) m[l]++;
    }

    ll maxim = (*m.begin()).second;
    for(auto i: m) maxim = max(maxim, i.second);
    cout << maxim;

    return (0);
}