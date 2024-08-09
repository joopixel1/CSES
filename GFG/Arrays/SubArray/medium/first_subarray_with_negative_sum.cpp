#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "Starting..." << "\n";

    ll n;
    cin >> n;
    vector<ll> v(n); 
    for(size_t i=0; i<n; i++) cin >> v[i];

    vector< pair<ll, ll> > p;
    for(size_t i=0,j=0; j<v.size(); j++, i++){
        if(v[j]<0){
            ll sum = v[i];
            while(i >= 0 and (sum+=v[i-1])<0) i--;
            p.push_back( make_pair(i, j) );
            i=j;
        }
    }

    auto ans = *min_element(p.begin(), p.end());
    cout << ans.first << " " << ans.second;

    return (0);
}
