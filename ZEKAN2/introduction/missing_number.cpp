#include <iostream>
#include <set>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // cout << "Starting..." << "\n";

    ll n, a;
    cin >> n;

    set<ll> s;
    for(int i=1; i<=n; i++) s.insert(i);

    for(int i=1; i<n; i++) {
        cin >> a;
        s.erase(a);
    }
    
    cout << *s.begin();

    return (0);
}