#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "Starting..." << "\n";

    ll n, sum=0; 
    cin >> n;
    
    vector<ll> a(n);
    for(size_t i=0; i<a.size(); i++) cin >> a[i];

    vector<ll> b(n);
    for(size_t i=0; i<b.size(); i++) b[i] = sum = sum+a[i];

    size_t j=0;
    for(j=0; j<b.size(); j++){
        if(sum - b[j] == b[j]) break;
    }

    if(j == n) cout << "IMPOSSIBLE";
    else {
        for(size_t i=0; i<=j; i++) cout << a[i] << " ";
        cout << "\n";
        for(size_t i=j+1; i<n; i++) cout << a[i] << " ";
        cout << "\n";
    }

    return (0);
}