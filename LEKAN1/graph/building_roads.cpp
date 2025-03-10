#include <iostream>
#include <vector> 

using namespace std;

typedef long long ll;

void dfs(vector< vector< ll > >& _g, vector< ll >& _visited, ll v, ll x){
    _visited[v] = x;
    
    for(auto n: _g[v]) {
        if(!_visited[n]) dfs(_g, _visited, n, x);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // cout << "Starting..." << "\n";

    ll n, m;
    cin >> n >> m;

    vector< vector< ll > > g(n, vector< ll >());
    ll a, b;
    for(ll i=0; i<m; i++){
        cin >> a >> b;
        g[a-1].push_back(b-1);
        g[b-1].push_back(a-1);
    }

    vector<ll> color(n, 0);
    ll ans = 0;
    vector< ll > edge;
    for(ll i=0; i<n; i++){
        if(!color[i]) {
            dfs(g, color, i, ++ans);
            edge.push_back(i);
        }
    }

    cout << ans-1 << "\n";
    for(ll i=1; i<edge.size(); i++) cout << edge[i-1]+1 << " " << edge[i]+1 << "\n";

    return 0;
}