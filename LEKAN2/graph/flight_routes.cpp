#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <tuple>

#define INF 1000000007

using namespace std;
using ll = long long;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // cout << "Starting..." << '\n';

    ll v, e, k, a, b, c;
    cin >> v >> e >> k;
    unordered_map< ll, vector< pair<ll, ll> > > graph;
    for(ll i=0; i<e; i++){
        cin >> a >> b >> c;
        graph[a].push_back( make_pair(b, c) );
    }

    vector<ll> dist(v+1, INF);
    priority_queue< tuple<ll, ll, ll> , vector<tuple<ll, ll, ll>>, greater<tuple<ll, ll, ll>> > pq;
    dist[0] = 0;
    pq.push( make_tuple(0, 0, 1) );
    while(!pq.empty()){
        auto [weight, from, to] = pq.top();
        pq.pop();
        
        dist[to] = dist[from]+weight;
        if(to == v){
            cout << dist[to] << " ";
            if(--k == 0) break;
        }

        for(auto i: graph[to]) pq.push( make_tuple(i.second, to, i.first) );
    }

    return (0);
}