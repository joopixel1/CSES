#include <iostream>
#include <string>
#include <map>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "Starting..." << "\n";

    string s;
    cin >> s;
    ll k;
    cin >> k;

    map<string, ll> m;
    for(size_t i=0; i<s.size()-k; i++) m[s.substr(i, k)]++;

    for(auto a: m){
        if(a.second > 1) cout << a.first << " - " << a.second << "\n";
    }

    return (0);
}