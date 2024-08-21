#include <iostream>
#include <set>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // cout << "Starting..." << "\n";

    ll n, k;
    cin >> n >> k;
    set<ll> s;
    for(ll i=1; i<=n; i++) s.insert(i);

    auto i = s.begin();
    while(!s.empty()){
        for(ll j=0; j<k; j++){
            if(i == s.end()) i=s.begin();
            ++i;
        }
        if(i == s.end()) i=s.begin();
        cout << *i << " ";
        i = s.erase(i);
    }

    return (0);
}