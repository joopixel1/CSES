#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <climits>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // cout << "Starting..." << "\n";

    ll n, m, a, b, c;
    cin >> n >> m;
    vector< tuple<ll, ll, ll> > edges;
    for(ll i=0; i<m; i++){
        cin >> a >> b >> c;
        edges.push_back( make_tuple(a-1, b-1, c) );
    }
    sort(edges.begin(), edges.end());

    vector<ll> dist(n, LLONG_MIN);
    dist[0] = 0;
    for(ll i=0; i<n-1; i++){
        for(auto e: edges){
            a = get<0>(e), b = get<1>(e), c = get<2>(e);
            if(dist[a] != LLONG_MIN){
                dist[b] = max(dist[b], dist[a]+c);
            }
        }
    }
    ll past = dist[n-1];

    // Cycle detection step: check if any distance can still be relaxed
    bool hasPositiveCycle = false;
    for(auto e : edges){
        a = get<0>(e), b = get<1>(e), c = get<2>(e);
        if(dist[a] != LLONG_MIN && dist[a] + c > dist[b]){
            if(b == n - 1){  // If the cycle affects the last node
                hasPositiveCycle = true;
                break;
            }
        }
    }

    // Output the result
    cout << (hasPositiveCycle ? -1 : past) << "\n";

    return (0);
}