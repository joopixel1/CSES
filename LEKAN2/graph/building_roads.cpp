#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <queue>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // cout << "Starting..." << "\n";

    ll n, m, a, b;
    cin >> n >> m;
    map<ll, vector<ll>> u;
    for(ll i=0; i<m; i++){
        cin >> a >> b;
        u[a].push_back(b);
        u[b].push_back(a);
    }

    vector<ll> v(n, 0);
    vector<ll> forest;
    for(size_t i=1; i<=v.size(); i++){
        if(v[i-1] == 0){
            forest.push_back(i);

            queue<ll> q;
            q.push(i);
            while(!q.empty()){
                ll a = q.front();
                if(v[a-1] == 0){
                    for(auto z: u[a]) q.push(z);
                    v[a-1] = forest.size();
                }
                q.pop();
            }
        }
    }
    
    vector< pair<ll, ll> > ans;
    for(size_t i=1; i<forest.size(); i++){
        ans.push_back( make_pair(forest[i-1], forest[i]) );        
    }

    cout << ans.size() << "\n";
    for(auto i: ans){
        cout << i.first << " " << i.second << "\n";
    }

    return 0;
}