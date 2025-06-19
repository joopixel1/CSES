#include <iostream>
#include <unordered_map>
#include <vector>
#include <deque>
#include <algorithm>


using namespace std;
using ll = long long;


bool dfs(unordered_map<ll, vector<ll>>& graph, vector<ll>& color, int u, vector<ll>& solution){
    if(color[u] == 1) {
        solution.push_back(u);
        return true;
    }

    color[u] = 1;
    for(auto i: graph[u]){
        if(dfs(graph, color, i, solution)){
            if(solution.size() < 2 or solution.front() != solution.back()) solution.push_back(u);
            color[u] = 2;
            return true;
        }
    }

    color[u] = 2;
    return false;
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

    vector<ll> color(v+1, 0);
    vector<ll> solution;
    for(size_t i=1; i<=v; i++){
        if(!color[i]) {
            if (dfs(graph, color, i, solution)){
                cout << solution.size() << '\n'; 
                reverse(solution.begin(), solution.end());   
                for (auto i: solution) cout << i << " ";
                return (0);
            }
        }
    }
    
    cout << "IMPOSSIBLE";
    return (0);
}
