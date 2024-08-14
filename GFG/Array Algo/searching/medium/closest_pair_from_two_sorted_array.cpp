#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "Starting..." << "\n";

    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> l_n(n);
    vector<ll> l_m(m);
    for(size_t i=0; i<l_n.size(); i++) cin >> l_n[i];
    for(size_t i=0; i<l_m.size(); i++) cin >> l_m[i];

    pair<ll, ll> closest = make_pair(l_n.front(), l_m.back());
    for (auto a=l_n.begin(), b=l_m.end()-1; a<l_n.end() and b>=l_m.begin(); ){
        ll temp = *a + *b;
        ll curr = closest.first + closest.second;

        if(abs(temp-k) < abs(curr-k) ) closest = make_pair(*a, *b);

        if(temp < k) a++;
        else b--;
    }

    cout << closest.first << " " << closest.second;

    return (0);
}