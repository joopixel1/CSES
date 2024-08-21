#include <iostream>
#include <set>

using namespace std;
using ll = long long;

typedef struct element {
    ll e, p;

    bool operator<(const element& other) const {
        return p > other.p;
    }
} element_t;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // cout << "Starting..." << "\n";

    ll n, k, t;
    cin >> n >> k;
    set<element_t> s;
    for(ll i=0; i<n; i++){
        cin >> t;
        s.insert({ t, t });
    }

    for(ll i=0; i<k; i++){
        auto p = (--s.end());
        s.erase(p);
        element_t a = *p;
        s.insert({ a.e, a.p+a.e });
    }

    ll maxim=0;
    for(auto a: s){
        maxim = max(maxim, a.p-a.e);
    }

    cout << maxim;

    return (0);
}