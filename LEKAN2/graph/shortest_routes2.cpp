#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <climits>

using namespace std;
using ll = long long;

// floyd_warshall
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // cout << "Starting..." << "\n";

    ll n, m, o, a, b, c;
    cin >> n >> m >> o;
    vector< vector<ll> > graph(n, vector<ll>(n, LLONG_MAX));
    for(ll i=0; i<m; i++){
        cin >> a >> b >> c;
        graph[a-1][b-1] = graph[b-1][a-1] = min(graph[a-1][b-1], c);
    }

    for(ll i=1; i<=n; i++) graph[i-1][i-1] = 0;
    
    for(ll k=1; k<=n; k++){
        for(ll i=1; i<=n; i++){
            for(ll j=1; j<=n; j++){
                if(graph[i-1][k-1] != LLONG_MAX and graph[k-1][j-1] != LLONG_MAX) graph[i-1][j-1] = min(graph[i-1][j-1], graph[i-1][k-1] + graph[k-1][j-1]);
            }
        }
    }

    for(ll i=0; i<o; i++){
        cin >> a >> b;
        ll ans = graph[a-1][b-1];
        cout << ((ans == LLONG_MAX) ? -1 : ans) << "\n";
    }

    return (0);
}