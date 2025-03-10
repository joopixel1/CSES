#include <iostream>
#include <vector> 
#include <queue>

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

    vector< bool > visited(n, false);
    vector< ll > from(n, -1);
    deque< ll > q;
    q.push_back(0);
    visited[0] = true;
    while(!q.empty()){
        ll current = q.front();
        q.pop_front();

        if(current == n-1){
            vector< ll > ans;
            for(; from[current] != -1; current = from[current]){
                ans.push_back(current);
            }
            cout << ans.size()+1 << "\n";
            cout << current+1 << " ";
            for(auto i=ans.rbegin(); i!=ans.rend(); i++) cout << (*i)+1 << " ";
            cout << "\n";
            return (0);
        }

        for(auto i: g[current]){
            if(!visited[i]) {
                q.push_back(i); 
                visited[i] = true;
                from[i] = current;
            }
        }
    }

    cout << "IMPOSSIBLE" << "\n";
    return 0;
}