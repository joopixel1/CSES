#include <iostream>
#include <unordered_map>
#include <vector>
#include <deque>


using namespace std;
using ll = long long;


bool bfs(unordered_map<ll, vector<ll>>& graph, vector<ll>& color, int u){
    deque<int> q;
    color[u] = 1;
    q.push_back(u);
    while(!q.empty()){
        int n = q.front();
        q.pop_front();

        for(auto i: graph[n]){
            if(color[i] == 0) {
                color[i] = (color[n] == 1) ? 2 : 1;
                q.push_back(i);
            }
            else if(color[i] == color[n]) return false;
        }
    }
    return true;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // cout << "Starting..." << '\n';

    ll v, e, a, b;
    cin >> v >> e;
    unordered_map<ll, vector<ll>> graph;
    for(ll i=0; i<e; i++){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<ll> color(v+1, 0);
    for(size_t i=1; i<=v; i++){
        if(!color[i]) {
            if (!bfs(graph, color, i)){
                cout << "IMPOSSIBLE";
                return (0);
            }
        }
    }

    for (ll i=1; i<=v; i++) cout << color[i] << " ";
    return (0);
}
