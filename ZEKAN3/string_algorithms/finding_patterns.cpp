#include <iostream>
#include <string>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // cout << "Starting..." << endl;

    string s, p;
    ll n;
    cin >> s >> n;

    for(ll i=0; i<n; i++) {
        cin >> p;
        if (s.find(p) == string::npos) cout << "NO" << "\n";
        else cout << "YES" << "\n";
    }

    return (0);
}