#include <iostream>
#include <vector> 
#include <queue>

#define UNVISITED 0
#define VISITED 1
#define COMPLETED 2

typedef long long ll;

using namespace std;

bool dfs(vector< vector< ll > >& _g, vector< ll >& _status, deque< ll >& _stack, ll v){
    if(_status[v] == VISITED) return false;
    else if(_status[v] == COMPLETED) return true;
    else{
        _status[v] = VISITED;
        for(auto n: _g[v]){
            if(!dfs(_g, _status, _stack, n)) return false;
        }
        _stack.push_back(v);
        _status[v] = COMPLETED;
        return true;
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
    }

    deque< ll > stack;
    vector< ll > color(n, UNVISITED);
    for(ll i=0; i<n; i++){
        if(!color[i]) {
            if(!dfs(g, color, stack, i)) {
                cout << "IMPOSSIBLE" << "\n";
                return 0;
            }
        }
    }

    for(; !stack.empty(); stack.pop_back()) cout << stack.back() + 1 << " ";
    cout << "\n";
    return 0;
}