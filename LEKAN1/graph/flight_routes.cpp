#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

typedef long long ll;

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, m, k, a, b, c;
    cin >> n >> m >> k;
    vector< vector< tuple< ll, ll > > > g(n);
    for(ll i=0; i<m; i++){
        cin >> a >> b >> c;
        g[a-1].push_back({b-1, c});
    }

    vector< ll > count(n, k);
    priority_queue< tuple< ll, ll >, vector< tuple< ll, ll > >, greater< tuple< ll, ll > > > pq;
    pq.push({0, 0});
    while(!pq.empty()){
        auto [d, i] = pq.top();
        pq.pop();

        if(i == n-1){
            cout << d << " ";
            k--;
            if(!k) break;
        }

        if(count[i]) {
            count[i]--;
            for(auto [e, l]: g[i]){
                pq.push({d+l, e});
            }
        }
    }

    cout << "\n";
    return 0;
}