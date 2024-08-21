#include <iostream>
#include <set>
 
using namespace std;
using ll = long long;
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    // cout << "Starting..." << "\n";
 
    ll n, a, b;
    cin >> n;
    set< pair<ll, ll> > s;
    for(ll i=0; i<n; i++){
        cin >> a >> b;
        s.insert( make_pair(b, a) );
    }
 
    ll ans = 0, end=0;
    for(auto j=s.begin(); j!=s.end();){
        if((*j).second >= end) {
            ans++;
            end = (*j).first;
        }
        j++;
    }
 
    cout << ans;
 
    return (0);
}