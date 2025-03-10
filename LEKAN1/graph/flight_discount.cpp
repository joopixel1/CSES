#include <iostream>
#include <set>
#include <tuple>
#include <numeric>
#include <vector>
#include <climits>

typedef long long ll;

using namespace std;

void find_paths(vector< vector< tuple< ll, ll > > > _rg, vector< bool >& _checked, ll& _ans, ll total, ll maxim, ll v){
    if (v == 0){
        _ans = min(_ans, total - maxim + (maxim/2));
    }
    else{
        if(!_checked[v]){
            _checked[v] = true;
            for(auto [n, l]: _rg[v]){
                ll new_total = total+l, new_maxim = max(maxim, l);
                find_paths(_rg, _checked, _ans, new_total, new_maxim, n);
            }
            _checked[v] = false;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, m, a, b, c, ans=LLONG_MAX;
    cin >> n >> m;
    vector< vector< tuple< ll, ll > > > rg(n);
    for(ll i=0; i<m; i++){
        cin >> a >> b >> c;
        rg[b-1].push_back({a-1, c});
    }

    multiset< ll > ms;
    vector< bool > checked(n, false);
    find_paths(rg, checked, ans, 0, 0, n-1);

    cout << ans << "\n";
    return 0;
}