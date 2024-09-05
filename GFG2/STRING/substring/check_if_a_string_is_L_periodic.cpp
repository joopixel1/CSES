#include <iostream>
#include <string>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    ll k;
    cin >> k;

    size_t pos = 0;
    string sub = s.substr(pos, k);
    pos += k;
    bool ans = true;
    while(pos < s.size()){
        if(sub.substr( 0, min(k, (ll)(s.size() - pos)) ) != s.substr( pos, min(k, (ll)(s.size() - pos))) ) {
            ans = false;
            break;
        }
        pos += k;
    }

    if(ans) cout << "true";
    else cout << "false";

    return (0);
}