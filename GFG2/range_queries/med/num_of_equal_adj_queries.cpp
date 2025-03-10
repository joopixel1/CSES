#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cout << "Starting..." << "\n";

    ll n, m, past, current;
    cin >> n >> m;

    cin >> past;
    vector< ll > v(n);
    for(ll i=0; i<n-1; i++) {
        cin >> current;
        v[i] = current == past;
        past = current;
    }


    vector< ll > ps(n, 0);
    for(ll i=0; i<n-1; i++) ps[i+1] = ps[i] + v[i];

    ll a, b;
    for(ll i=0; i<m; i++){
        cin >> a >> b;
        cout << ps[b] - ps[a] << "\n";
    }
    
    return (0);
}