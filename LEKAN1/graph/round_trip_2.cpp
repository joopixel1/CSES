#include <iostream>
#include <vector> 

#define UNVISITED 0
#define VISITED 1
#define COMPLETED 2

typedef long long ll;

using namespace std;

ll find_cycle(vector< vector< ll > >& _g, vector< ll >& _status, vector< ll >& _from, ll v, ll x){
    _from[v] = x;

    if(_status[v] == COMPLETED) {
        return -1;
    }
    else if(_status[v] == VISITED){
        return v;
    }
    else {
        _status[v] = VISITED;
        for(auto n: _g[v]) {
            ll ans = find_cycle(_g, _status, _from, n, v);
            if(ans != -1) return ans;
        }
        _status[v] = COMPLETED;
        return -1;
    }   
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // cout << "Starting..." << "\n";

    ll n, m;
    cin >> n >> m;

    vector< vector< ll > > g(n, vector< ll >());
    ll a, b;
    for(ll i=0; i<m; i++){
        cin >> a >> b;
        g[a-1].push_back(b-1);
    }

    vector< ll > color(n, UNVISITED);
    vector<ll> from(n, -1);
    for(ll i=0; i<n; i++){
        if(!color[i]) {
            ll start = find_cycle(g, color, from, i, -1);
            if(start != -1){
                vector<ll> ans;
                ans.push_back(start);
                for(ll j=from[start]; j != start; j = from[j]) ans.push_back(j);
                ans.push_back(start);

                cout << ans.size() << "\n";
                for(auto i=ans.rbegin(); i!=ans.rend(); i++) cout << (*i) + 1 << " ";
                cout << "\n";
                return 0;
            }
        }
    }

    cout << "IMPOSSIBLE" << "\n";
    return 0;
}