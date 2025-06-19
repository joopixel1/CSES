#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <climits>

using namespace std;
using ll = long long;

// dijkstra
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // cout << "Starting..." << "\n";

    ll n, m, a, b, c;
    cin >> n >> m;
    map< ll, vector<pair<ll, ll>> > graph;
    for(ll i=0; i<m; i++){
        cin >> a >> b >> c;
        graph[a].push_back( make_pair(b, c) );
    }

    vector<bool> selected(n, false);
    vector<ll> dist(n, LLONG_MAX);
    dist[0] = 0;
    multimap<ll, ll> pq;
    pq.insert( make_pair(0, 1) );
    for(; !pq.empty(); ){
        auto i = pq.begin();
        ll node_dist = (*i).first;
        ll node = (*i).second;
        if(!selected[node-1]){
            for(auto j: graph[node]){
                if(!selected[j.first-1]){
                    if(node_dist+j.second < dist[j.first-1]){
                        dist[j.first-1] = node_dist+j.second;
                        pq.insert( make_pair( dist[j.first-1], j.first) );
                    }
                }
            }
            selected[node-1] = true;
        }
        pq.erase(i);
    }

    for(auto i: dist) cout << i << " ";

    return (0);
}