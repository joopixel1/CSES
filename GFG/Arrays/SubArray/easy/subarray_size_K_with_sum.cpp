#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "Starting..." << "\n";

    ll n, k, s, sum=0; 
    cin >> n >> k >> s;
    
    vector<ll> a(n);
    for(size_t i=0; i<a.size(); i++) cin >> a[i];

    vector<ll> b(n);
    for(size_t i=0; i<b.size(); i++) b[i] = sum = sum+a[i];

    size_t j=0;
    for(j=0; j<b.size()-k; j++){
        if(b[j+k] - b[j] == s) break;
    }

    if(j == n-k) cout << "NO";
    else cout << "YES";

    return (0);
}