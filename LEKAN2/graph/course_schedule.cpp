#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>


using namespace std;
using ll = long long;


bool dfs(unordered_map<ll, vector<ll>>& graph, ll u, vector<ll>& visited, deque<ll>& my_stack){
    visited[u]=1;
    // bool ans = true;
    for(auto i: graph[u]){
        if(visited[i] == 1) return false;
        if(!visited[i]) {
            if(!dfs(graph, i, visited, my_stack)) return false;
        }
    }
    my_stack.push_back(u);
    visited[u] = 2;
    return true;
}

bool topological_sort(ll v, unordered_map<ll, vector<ll>>& graph, deque<ll>& my_Stack){
   vector<ll> visited(v+1, 0);
    for(ll i=1; i<=v; i++){
        if(!visited[i]) {
            if(!dfs(graph, i, visited, my_Stack)) return false;
        }
    }
    return true;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll v, e, a, b;
    cin >> v >> e;
    unordered_map<ll, vector<ll>> graph;
    for(ll i=0; i<e; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
    }

    deque<ll> my_stack;
    if(!topological_sort(v, graph, my_stack)) cout << "IMPOSSIBLE";
    else{
        while(!my_stack.empty()) {
            cout << my_stack.back() << " ";
            my_stack.pop_back();
        }
    }

    return (0);
}