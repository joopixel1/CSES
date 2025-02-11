#include <iostream>
#include <vector>
#include <deque>

using namespace std;
using ll = long long;


ll calculate_dest(ll node, vector<ll>& selected, const vector<vector<ll>>& graph){
    deque<ll> q;
    q.push_back(node);
    selected[node] = node+1;
    ll count = 0;
    while(!q.empty()){
        ll t = q.front();
        for(auto i: graph[t]) {
            if(selected[i] != node+1) {
                q.push_back(i);
                selected[i] = node+1;
            }
        }
        q.pop_front();
        count++;
    }
    return count;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    // cout << "Starting...";

    int n, m, a, b;
    cin >> n >> m;
    vector<ll> selected(n, 0);
    vector<vector<ll>> store(n, vector<ll>());
    for(int i=0; i<m; i++){
        cin >> a >> b;
        store[a-1].push_back(b-1);
    }

    for(int i=0; i<n; i++) cout << calculate_dest(i, selected, store) << " ";

    return 0;
}
