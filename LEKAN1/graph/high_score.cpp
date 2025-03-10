#include <iostream>
#include <vector>
#include <tuple>
#include <climits>

typedef long long ll;

using namespace std;

void relax(vector< tuple< ll, ll, ll > >& _edges, vector< ll >& _distance, vector< ll >& _from){
    for(ll i=0; i<_edges.size(); i++){
        auto [x, y, z] = _edges[i];
        if(_distance[x] != LLONG_MIN){
            auto val = _distance[x] + z;
            if(val > _distance[y]) {
                _distance[y] = val;
                _from[y] = x;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // cout << "Starting..." << "\n";

    ll n, m, a, b, c;
    cin >> n >> m;
    vector< tuple< ll, ll, ll > > edges;
    for(ll i=0; i<m; i++){
        cin >> a >> b >> c;
        edges.push_back({a-1, b-1, c});
    }

    vector< ll > distance(n, LLONG_MIN);
    vector< ll > from(n, -1);
    distance[0]= 0;
    for(ll j=0; j<n-1; j++) relax(edges, distance, from);

    vector< ll > path;
    path.push_back(n-1);
    while(path.back() != 0){
        path.push_back(from[path.back()]);
    }
    
    for(auto i: from) cout << i << " ";
    cout << endl;
    for(auto i: path) cout << i << " ";
    cout << endl;

    vector< ll > final(distance);
    relax(edges, final, from);

    for(ll v: path) {
        if(final[v] != distance[v]) {
            cout << -1 << "\n";
            return 0;
        }
    }
    
    cout << distance[n-1] << "\n";
    return 0;
}