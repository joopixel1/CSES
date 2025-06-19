#include <iostream>
#include <unordered_map>
#include <vector>

#define PRIME_MOD 1000000007


using namespace std;
using ll = long long;


void custom_dfs(unordered_map<ll, vector<ll>>& graph, ll u, ll target, vector<ll>& visited, vector<ll>& routes){
    visited[u] = 1;
    if(u == target) routes[u] = 1;
    else{
        ll ans = 0;
        for(auto i: graph[u]){
            if(!visited[i]) custom_dfs(graph, i, target, visited, routes);
            ans = (ans + routes[i]) %PRIME_MOD;
        }
        routes[u] = ans;
    }
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

    vector<ll> visited(v+1, 0), routes(v+1, 0);
    custom_dfs(graph, 1, v, visited, routes);
    cout << routes[1];

    return (0);
}
