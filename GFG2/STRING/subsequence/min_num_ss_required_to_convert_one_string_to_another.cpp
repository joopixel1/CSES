#include <iostream>
#include <string>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // cout << "Starting..." << "\n";

    string a, b;
    cin >> a >> b;

    ll ans = 1, ind = 0;

    for(auto i: b){
        while(a[ind++] != i) {
            if(ind >= a.size()) ind = 0, ans++;
        }
    }

    cout << ans;

    return (0);
}