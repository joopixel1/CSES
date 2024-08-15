#include <iostream>
#include <set>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, t;
    cin >> n;
    multiset<ll> s;
    for(ll i=0; i<n; i++){
        cin >> t;
        s.insert(t);
    }

    ll cost = 0;
    while(s.size() > 1){
        ll a = *s.begin();
        s.erase(s.begin());
        ll b = *s.begin();
        s.erase(s.begin());
        cost += (a+b);
        s.insert(a+b);
    }

    cout << cost;

    return (0);
}