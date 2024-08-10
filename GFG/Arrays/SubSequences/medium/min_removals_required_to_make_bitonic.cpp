#include <iostream>
#include <vector>

using  namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;
    vector<ll> v(n);
    for(size_t i=0; i<v.size(); i++) cin >> v[i];

    vector<ll> inc(n), dec(n);
    inc[0] = dec[n-1] = 0;
    for(size_t i=1; i<v.size(); i++) {
        inc[i] = inc[i-1];
        if(v[i] <= v[i-1]) inc[i]++;
    }
    for(size_t i=v.size()-2; i<v.size(); i--) {
        dec[i] = dec[i+1];
        if(v[i] <= v[i+1]) dec[i]++;
    }

    ll minim = dec[0] + inc[0];
    for(size_t i=1; i<v.size(); i++) {
        minim = min(minim, inc[i] + dec[i]);
    }

    cout << minim;

    return (0);
}