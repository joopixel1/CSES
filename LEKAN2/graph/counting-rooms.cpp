#include <iostream>
#include <vector>
#include <set>

using namespace std;
using ll = long long;

void trace(ll i, ll j, vector<string>& v, vector<vector<ll>>& w, ll n){
    w[i][j] = n;
    if(i-1>=0 and v[i-1][j]=='.' and w[i-1][j]==0) trace(i-1, j, v, w, n);
    if(i+1<v.size() and v[i+1][j]=='.' and w[i+1][j]==0) trace(i+1, j, v, w, n);
    if(j-1>=0 and v[i][j-1]=='.' and w[i][j-1]==0) trace(i, j-1, v, w, n);
    if(j+1<v[0].size() and v[i][j+1]=='.' and w[i][j+1]==0) trace(i, j+1, v, w, n);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // cout << "Starting..." << "\n";

    ll n, m;
    cin >> n >> m;
    string s;
    vector<string> v;
    for (ll i=0; i<n; i++) {
        cin >> s;
        v.push_back(s);
    }

    vector< vector<ll> > w(n, vector<ll>(m, 0));
    ll maxim  = 0;
    for(ll i=0; i<n; i++){
        for(ll j=0; j<m; j++){
            if(v[i][j] == '.' and w[i][j] == 0){
                trace(i, j, v, w, ++maxim);
            }
        }
    }

    cout << maxim;

    return (0);
}