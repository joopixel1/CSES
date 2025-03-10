#include <iostream>
#include <vector>
#include <string>

typedef long long ll;

using namespace std;

bool find_route(vector< string >& _g, vector< tuple< ll, ll > >& _monsters, vector< char >& _path, ll m, ll i, ll j){
    if(!m){
        _path.push_back('L');
        if(find_route(_g, _monsters, _path, )) return true;
        _path.pop_back();

        _path.push_back('R');
        if(find_route(_g, )) return true;
        _path.pop_back();
    }
    if(at_edge()) return true;

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // cout << "Starting..." << "\n";
    
    ll n, m;
    cin >> n >> m;
    vector< string > v;
    for(ll i=0; i<n; i++){
        string s;
        cin >> s;
        v.push_back(s);
    }

    

    return 0;
}

