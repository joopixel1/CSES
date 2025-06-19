#include <iostream>
#include <vector>
#include <tuple>
#include <set>
#include <unordered_map>
#include <deque>

#define INF 1000000007


using namespace std;
using ll = long long;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // cout << "Starting..." << '\n';

    ll v, e, a, b, c;
    cin >> v >> e;
    vector<tuple<ll, ll, ll>> edges(e);
    unordered_map<ll, vector<pair<ll, ll>>> T;
    for(ll i=0; i<e; i++){
        cin >> a >> b >> c;
        edges[i] = make_tuple(a, b, c);
        T[a].push_back( make_pair(b, c) );
    }    
    for(ll i=1; i<=v; i++) edges.push_back( make_tuple(0, i, 0) );

    vector<ll> dist(v+1, INF);
    vector<ll> path(v+1, 0);
    dist[0] = 0;
    for(ll i=0; i<v; i++){
        // relax edges
        for(auto j: edges){
            ll from = get<0>(j), to = get<1>(j), weight = get<2>(j);
            if(dist[from] != INF and dist[from] + weight <= dist[to]) {
                dist[to] = dist[from]+weight;
                path[to] = from;
            }
        }
    }

    vector<ll> final(dist);
    // relax edges 1 more time;
    for(auto j: edges){
        ll from = get<0>(j), to = get<1>(j), weight = get<2>(j);
        if(final[from] != INF and final[from] + weight <= final[to]) {
            final[to] = final[from]+weight;
            path[to] = from;
        }
    }

    int i=1;
    while(i <= v and dist[i] == final[i]) i++;


    if(i == v+1) cout << "NO" << '\n';
    else {
        cout << "YES" << '\n';
        deque<ll> s;
        for(ll j=1; j<=2*v; j++) {
            s.push_back(i);
            i = path[i];
        } 

        ll first = s.back();
        cout << first << " ";
        s.pop_back();
        while(s.back() != first){
            cout << s.back() << " ";
            s.pop_back();
        }
        cout << first << " ";
    }

    return (0);
}