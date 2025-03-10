#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <climits>

using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // cout << "Starting..." << "\n";

    ll n, m, a, b, c;
    cin >> n >> m;
    vector< vector< tuple< ll, ll > > > g(n);
    for(ll i=0; i<m; i++){
        cin >> a >> b >> c;
        g[a-1].push_back({ b-1, c });
    }

    vector< ll > distance(n, LLONG_MAX);
    vector< ll > found(n, false);
    priority_queue< tuple< ll, ll >, vector< tuple< ll , ll > >, greater< tuple< ll, ll > > > pq;
    distance[0] = 0;
    pq.push({0, 0});
    while(!pq.empty()){
        auto [d, n] = pq.top();
        pq.pop();

        if(!found[n]){
            found[n] = true;
            for(auto [v, l]: g[n]){
                if(d+l < distance[v]){
                    distance[v] = d+l;
                    pq.push({d+l, v});
                }
            }
        }
    }

    for(auto i: distance) cout << i << " ";
    return 0;
}