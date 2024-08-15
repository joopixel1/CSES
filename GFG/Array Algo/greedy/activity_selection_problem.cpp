#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "Starting..." << "\n";

    ll n;
    cin >> n;
    vector<ll> s(n), f(n);
    for(size_t i=0; i<s.size(); i++) cin >> s[i];
    for(size_t i=0; i<f.size(); i++) cin >> f[i];

    vector< pair<ll, ll> > t(n);
    for(size_t i=0; i<t.size(); i++) t[i] = make_pair(f[i], s[i]);
    sort(t.begin(), t.end());

    set< pair<ll, ll> > a;
    a.insert(t[0]);
    for(size_t i=1; i<t.size(); i++) {
        ll last = (*a.rbegin()).first;
        if(t[i].second > last) a.insert(t[i]);
    }

    for(auto i: a) cout << i.first << " " << i.second << "\n";

    return (0);
}