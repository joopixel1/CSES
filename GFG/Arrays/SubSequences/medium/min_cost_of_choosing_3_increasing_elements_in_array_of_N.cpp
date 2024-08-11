#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "Starting..." << "\n";

    ll n, minim=0, first=0, curr=0;
    cin >> n;
    vector<ll> v(n), c(n);
    for(size_t i= 0; i<v.size(); i++) cin >> v[i];
    for(size_t i= 0; i<c.size(); i++) cin >> c[i];

    for(size_t i=0; i<v.size(); i++) {
        curr += c[i];
        for(size_t j=i+1; j<v.size(); j++) {
            if(v[j] <= v[i]) continue;
            curr += c[j];
            for(size_t k=j+1; k<v.size(); k++) {
                if(v[k] <= v[j]) continue;
                curr += c[k];
                if(first) minim = min(minim, curr);
                else first=1, minim = curr;
                curr -= c[k];
            }
            curr -= c[j];
        }
        curr -= c[i];
    }

    cout << minim;

    return (0);
}