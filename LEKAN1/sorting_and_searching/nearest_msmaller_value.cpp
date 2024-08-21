#include <iostream>
#include <set>
#include <map>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "Starting..." << "\n";

    ll n, t;
    cin >> n;
    map<ll, ll> m;
    for(ll i=1; i<=n; i++){
        cin >> t;
        if(!m.count(t)) m[t] = i;
        try{
            auto it = --m.find(t);
            cout << (*it).second << " ";
        }
        catch(exception e){
            cout << 0 << " ";
        } 
    }

    return (0);
}