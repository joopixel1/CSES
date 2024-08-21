#include <iostream>
#include <set>
#include <vector>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // cout << "Starting..." << "\n";

    ll n, k, a, b;
    cin >> n >> k;
    multiset< pair<ll, ll> > s;
    for(ll i=0; i<n; i++){
        cin >> a >> b;
        s.insert( make_pair(b, a) );
    }

    ll ans = 0;
    vector<ll> end(k, 0);
    for(auto j=s.begin(); j!=s.end();){
        ll i=0;
        while(i<k and (*j).second < end[i]) i++;

        if(i != k) {
            ans++;
            end[i] = (*j).first;
            j = s.erase(j);
        }
        else j++;
    }

    cout << ans;

    return (0);
}