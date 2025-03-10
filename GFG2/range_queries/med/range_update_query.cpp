#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cout << "Starting..." << "\n";

    ll n, m, start;
    cin >> n >> m >> start;

    ll past = start, current;
    vector< ll > da(n-1, 0);
    for(ll i=0; i<n-1; i++) {
        cin >> current;
        da[i] = current - past;
        past = current;
    }

    string s;
    ll l, r, x;
    for(ll i=0; i<m; i++){
        cin >> s;
        if(s == "update"){
            cin >> l >> r >> x;
            if (l == 0) start += x;
            else da[l-1] += x;
            da[r] -= x;
        }
        else if(s == "print"){
            for(ll j=-1, k = start; j<n-1; k += da[++j]) cout << k << " ";
            cout << "\n";
        }
    }
    
    return (0);
}