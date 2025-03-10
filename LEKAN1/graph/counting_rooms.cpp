#include <iostream>
#include <vector> 

using namespace std;

typedef long long ll;

void fill(vector< vector< ll > >& _v, ll i, ll j, ll x){
    _v[i][j] = x;
    
    if(j+1 < _v[i].size() and !_v[i][j+1]) fill(_v, i, j+1, x);
    if(j-1 >= 0 and !_v[i][j-1]) fill(_v, i, j-1, x);
    if(i+1 < _v.size() and !_v[i+1][j]) fill(_v, i+1, j, x);
    if(i-1 >= 0 and !_v[i-1][j]) fill(_v, i-1, j, x);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // cout << "Starting..." << "\n";

    ll n, m;
    cin >> n >> m;

    vector< vector< ll > > v;
    string s;
    for(ll i=0; i<n; i++){
        cin >> s;
        vector< ll > t;
        for(auto c: s){
            if(c == '#') t.push_back(-1);
            else if(c == '.') t.push_back(0);
        }
        v.push_back(t);
    }
    
    ll ans = 0;
    for(ll i=0; i<n; i++){
        for(ll j=0; j<m; j++){
            if(!v[i][j]){
                fill(v, i, j, ++ans);
            }
        }
    }

    cout << ans << "\n";
    return 0;
}