#include <iostream>
#include <set>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // cout << "Starting..." << "\n";

    ll n, m, t;
    cin >> n >> m;
    set< pair<ll, ll> > p;
    p.insert( make_pair(0, n) );
    multiset<ll> s;
    s.insert(n);

    for(ll i=0; i<m; i++){
        cin >> t;
        auto z = --p.lower_bound( make_pair(t, 0) );
        ll width = (*z).second - (*z).first;
        auto a = make_pair((*z).first, t), b = make_pair(t, (*z).second);

        p.erase(z);
        p.insert(a);
        p.insert(b);
        
        s.erase(s.find(width));
        s.insert(a.second-a.first);
        s.insert(b.second-b.first);

        cout << *(s.rbegin()) << " ";
    }

    return (0);
}