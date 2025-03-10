#include <iostream>
#include <vector>
#include <tuple>
#include <climits>

typedef long long ll;

using namespace std;

ll find_cycle(vector< vector< tuple< ll, ll > > >& _g, vector< bool >& _visited, vector< ll >& _from, vector< ll >& _totals, ll v, ll x, ll total){
    ll old = _totals[v];
    _from[v] = x;
    _totals[v] = total;

    if(_visited[v]) {
        if(total  < old) return v;
        else return -1;
    }
    else {
        _visited[v] = true;
        for(auto [n, l]: _g[v]) {
            ll ans = find_cycle(_g, _visited, _from, _totals, n, v, total+l);
            if(ans != -1) return ans;
        }

        return -1;
    }   
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // cout << "Starting..." << "\n";

    ll n, m, a, b, c;
    cin >> n >> m;
    vector< tuple< ll, ll, ll > > edges;
    vector< vector< tuple< ll, ll > > > g(n, vector< tuple< ll, ll > >());
    for(ll i=0; i<m; i++){
        cin >> a >> b >> c;
        edges.push_back({a-1, b-1, c});
        g[a-1].push_back({b-1, c});
    }

   
    vector<bool> color(n, false);
    vector< ll > totals(n, LLONG_MIN);
    vector<ll> from(n, -1);
    for(ll i=0; i<n; i++){
        if(!color[i]) {
            ll start = find_cycle(g, color, from, totals, i, -1, 0);
            if(start != -1){
                vector<ll> ans;
                ans.push_back(start);
                for(ll j=from[start]; j != start; j = from[j]) ans.push_back(j);
                ans.push_back(start);

                cout << "YES" << "\n";
                for(auto i=ans.rbegin(); i!=ans.rend(); i++) cout << (*i) + 1 << " ";
                cout << "\n";
                return 0;
            }
        }
    }
    
    cout << "NO" << "\n";
    return 0;
}