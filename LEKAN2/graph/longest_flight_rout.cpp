#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <cmath>

#define INF 1000000007


using namespace std;
using ll = long long;


bool dfs(unordered_map<ll, vector<ll>>& graph, ll u, vector<ll>& visited, deque<ll>& my_stack){
    visited[u] = 1;
    for(auto i: graph[u]){
        if(visited[i] == 1) return false;
        if(!visited[i]){
            if(!dfs(graph, i, visited, my_stack)) return false;
        }
    }
    visited[u] = 2;
    my_stack.push_back(u);
    return true;
}

bool topological_sort(ll v, unordered_map<ll, vector<ll>>& graph, deque<ll>& my_stack){
    vector<ll> visited(v+1, 0);
    for(ll i=1; i<=v; i++){
        if(!visited[i]){
            if(!dfs(graph, i, visited, my_stack)) return false;
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
    }

    deque<ll> my_stack;
    if(!topological_sort(v, graph, my_stack)) cout << "IMPOSSIBLE";
    else {
        vector<ll> dist(v+1, INF);
        vector<ll> relaxer(v+1, 0);
        dist[1] = 0;
        while(!my_stack.empty()) {
            ll u = my_stack.back();
            my_stack.pop_back();

            if(dist[u] != INF){
                for(auto i: graph[u]){
                    if(dist[u]+(-1) < dist[i]) {
                        dist[i] = dist[u]+(-1);
                        relaxer[i] = u;
                    }
                }
            }
        }
        if(dist[v] == INF) cout << "IMPOSSIBLE";
        else {
            cout << abs(dist[v])+1 << '\n';

            ll pos = v;
            deque<ll> chelsea_stack;
            while(pos != 1){
                chelsea_stack.push_back(pos);
                pos = relaxer[pos];
            }
            chelsea_stack.push_back(pos);

            while(!chelsea_stack.empty()){
                pos = chelsea_stack.back();
                cout << pos << " ";
                chelsea_stack.pop_back();
            }
        }
    }

    return (0);
}
