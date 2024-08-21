#include <iostream>
#include <set>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // cout << "Starting..." << "\n";

    ll n;
    cin >> n;
    set<ll> s;
    for(ll i=1; i<=n; i++) s.insert(i);

    auto i = s.begin();
    while(!s.empty()){
        if(i == s.end()) i=s.begin();
        ++i;
        if(i == s.end()) i=s.begin();
        cout << *i << " ";
        i = s.erase(i);
    }

    return (0);
}