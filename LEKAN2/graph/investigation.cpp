#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 1000000007


using namespace std;
using ll = long long;


vector<ll> custom_dijkstra_from_1(ll v, unordered_map<ll, vector<pair<ll, ll>>>& graph){
    vector<ll> visited(v+1, 0), dist(v+1, INF), count(v+1, 0), maxim(v+1, -1), minim(v+1, INF);
    dist[0] = 0;
    count[0] = 1;
    priority_queue<tuple<ll, ll, ll, ll>, vector<tuple<ll, ll, ll, ll>>, greater<tuple<ll, ll, ll, ll>>> pq;
    pq.push( make_tuple(0, 0, 1, 0) );
    while(!pq.empty()){
        ll from = get<1>(pq.top()), to = get<2>(pq.top()), weight = get<0>(pq.top()), route = get<3>(pq.top());
        pq.pop();

        if(dist[from] + weight <= dist[to]){
            count[to] = (dist[from] + weight == dist[to]) ? (count[to]+count[from]) %INF : count[from];
            dist[to] = dist[from] + weight;
            maxim[to] = max(maxim[to], route);
            minim[to] = min(minim[to], route);

            for(auto i: graph[to]) pq.push( make_tuple(i.second, to, i.first, route+1) );
        }
    }

    return { dist[v], count[v], minim[v], maxim[v] };
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // cout << "Starting..." << '\n';

    ll v, e, a, b, c;
    cin >> v >> e;
    unordered_map<ll, vector<pair<ll, ll>>> graph;
    for(ll i=0; i<e; i++){
        cin >> a >> b >> c;
        graph[a].push_back( make_pair(b, c) );
    }

    for(auto i: custom_dijkstra_from_1(v, graph)) cout << i << " ";

    return (0);
}
