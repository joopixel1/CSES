#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "Starting..." << "\n";

    ll n;
    cin >> n;
    vector<ll> v(n); 
    for(size_t i=0; i<v.size(); i++) cin >> v[i];

    // turn into binary array
    vector<ll> b(n);
    b[0] = 1;
    for(size_t i=1; i<b.size(); i++) b[i] = (v[i] >= v[i-1]);

    // find length of longest ones after removing a group of zeros
    vector<ll> s(n);
    ll c=0;
    for(size_t i=1; i<b.size(); i++){
        if(b[i]) c++;
        else {
            if(c!=0){
                s.push_back(c);
                c=0;
            }
        }
    }
    if(c!=0) s.push_back(c);

    ll ans = s[0];
    for(size_t i=0; i<s.size()-1; i++){
        ans = max(ans, s[i]+s[i+1]);
    }

    cout << n-ans;
    return (0);
}
