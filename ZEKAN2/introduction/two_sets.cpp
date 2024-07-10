#include <iostream>
#include <set>

using namespace std;
using ll = long long;

ll triangle(ll a){
    return (a*(a+1))/2;
}

ll inv(ll a, ll b){
    return b+1-a;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // cout << "Starting..." << "\n";

    ll n;
    cin >> n;

    if(triangle(n) & 1) cout << "NO" << "\n";
    else{
        cout << "YES" << "\n";
        
        set<ll> s, l, r;
        for(ll i=1; i<=n; i++) s.insert(i);

        for(ll i=1, j=n/2; i<(n+1)/4; i++, j--) s.erase(i), l.insert(i), s.erase(inv(i, n)), l.insert(inv(i, n)),
            s.erase(j), r.insert(j), s.erase(inv(j, n)), r.insert(inv(j, n));
        
        auto it = s.begin();
        if(s.size() == 3) l.insert(*(it++)), l.insert(*(it++)), r.insert(*(it++));
        else l.insert(*(it++)), r.insert(*(it++)), r.insert(*(it++)), l.insert(*(it++));

        cout << l.size() << "\n";
        for(ll a: l) cout << a << " ";
        cout << "\n";
        cout << r.size() << "\n";
        for(ll a: r) cout << a << " ";
        cout << "\n";
    }
 
    return (0);
}