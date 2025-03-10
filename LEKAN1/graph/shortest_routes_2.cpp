#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <climits>

using namespace std;

typedef long long ll;

void relax(vector< vector< ll > >& _distance, ll n, ll v){
    for(ll i=0; i<n; i++){
        for(ll j=0; j<n; j++){
            if(_distance[i][v] != -1 and _distance[v][j] != -1){
                ll val = _distance[i][v] + _distance[v][j];
                if(_distance[i][j] == -1 or val < _distance[i][j]) _distance[i][j] = val;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // cout << "Starting..." << "\n";

    ll n, m, q, a, b, c;
    cin >> n >> m >> q;
    vector< vector< ll > > distance(n, vector< ll >(n, -1));
    for(ll i=0; i<n; i++) distance[i][i] = 0;
    for(ll i=0; i<m; i++){
        cin >> a >> b >> c;
        if(distance[a-1][b-1] == -1 or c < distance[a-1][b-1]) distance[a-1][b-1] = c;
        if(distance[b-1][a-1] == -1 or c < distance[b-1][a-1])distance[b-1][a-1] = c;
    }

    for(ll i=0; i<n; i++) relax(distance, n, i);


    for(ll i=0; i<q; i++) {
        cin >> a >> b;
        cout << distance[a-1][b-1] << "\n";
    }
    
    return 0;
}