#include <iostream>
#include <map>
#include <vector>
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

    vector<ll> v(n, -1);
    queue<ll> q;
    q.push(1);
    v[0] = 0;
    while(!q.empty()){
        ll f = q.front();
        for(auto i: u[f]){
            if(v[i - 1] == -1) {
                q.push(i);
                v[i-1] = f;
            }
        }
        q.pop();
    }

    if(v[n-1] == -1) cout << "IMPOSSIBLE";
    else{
        vector<ll> ans;
        ll pos = n;
        ans.push_back(pos);
        while(pos != 1){
            pos = v[pos-1];
            ans.push_back(pos);
        }
        cout << ans.size() << "\n";
        for(auto i=ans.rbegin(); i<ans.rend(); i++) cout << *i << " ";
        cout << "\n";
    }

    return (0);
}