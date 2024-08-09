#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "Starting..." << "\n";

    ll n, k;
    cin >> n >> k;
    vector<ll> v(n), s(n+1);
    for(size_t i=0; i<v.size(); i++) cin >> v[i];
    s[0] = 0;
    for(size_t i=1; i<=s.size(); i++) s[i] = s[i-1]+v[i-1];

    for(size_t i=s.size()-1; i>0; i--){
        for(size_t j=0; j<s.size()-i; j++){
            if((s[j+i] - s[j])%k != 0) {
                cout << i;
                return (0);
            }
        }
    }
        
    cout << -1;
    return (0);
}