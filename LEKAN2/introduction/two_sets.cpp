#include <iostream>
#include <vector>

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
        
        vector<ll> s, l, r;
        for(ll i=1; i<=n; i++) s.push_back(i);

        for(ll i=1, j=n/2; i<(n+1)/4; i++, j--) l.push_back(i), l.push_back(inv(i, n)), r.push_back(j), r.push_back(inv(j, n));
        
    
        if(n&1) l.push_back((n+1)/4), l.push_back(((n+1)/4) * 2), r.push_back(((n+1)/4) * 3);
        else l.push_back((n+1)/4), l.push_back(inv((n+1)/4, n)), r.push_back((n+1)/4 + 1), r.push_back(inv((n+1)/4 + 1, n));

        cout << l.size() << "\n";
        for(ll a: l) cout << a << " ";
        cout << "\n";
        cout << r.size() << "\n";
        for(ll a: r) cout << a << " ";
        cout << "\n";
    }
 
    return (0);
}