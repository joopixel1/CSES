#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;
using ll = long long;

bool isPerfectSquare(ll a){
    ll b = sqrt(a);
    return (b*b) == a;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "Starting..." << "\n";

    ll n, k, ans=0;
    cin >> n >> k;
    vector<ll> a(n);
    for(size_t i=0; i<a.size(); i++) cin >> a[i];
    
    vector<ll> b(n);
    for(size_t i=0; i<b.size(); i++) b[i] = isPerfectSquare(a[i]);

    map<ll, ll> c;
    for(ll i=0, current=0; i<b.size(); i++){
        current += b[i];

        if(current == k) ans++;

        if(c.count(current - k)) ans+= c[current-k];

        c[current]++;
    }

    cout << ans;

    return (0);
}