#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // cout << "Starting..." << "\n";

    ll n, a, b;
    cin >> n;

    vector< tuple<ll, ll, ll> > v;
    for(int i=0; i<n; i++){
        cin >> a >> b;
        v.push_back( make_tuple(b-a, a, b) );
    }
    // sort(v.begin(), v.end());

    multiset< pair<ll, ll> > s;
    for(size_t i=0; i<v.size(); i++){
        pair<ll, ll> t = make_pair(get<1>(v[i]), get<2>(v[i]));
        auto ref = s.upper_bound(t);
        if(ref == s.end() or ref == s.begin()) s.insert(t);
        else {
            if(t.second <= (*ref).first){
                ref--;
                if(t.first >= (*ref).second) s.insert(t);
            }
        }
    } 

    cout << s.size();

    return (0);
}