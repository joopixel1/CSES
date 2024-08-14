#include <iostream>
#include <vector>
#include <set>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "Starting..." << "\n";

    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for(size_t i=0; i<v.size(); i++) cin >> v[i];

    bool ans = false;
    set<ll> sums;
    for(size_t i=0; i<v.size(); i++){
        if(v[i] == k){
            ans = true;
            break;
        }
        else if(v[i] < k){
            if(sums.find(k - v[i]) != sums.end()){  
                ans = true;
                break;
            } 
            set<ll> temp(sums);
            for(auto a : temp){
                if(a + v[i] < k) sums.insert(a + v[i]);
                else break;
            }
            sums.insert(v[i]);
        }
    }

    cout << ans;
    

    return (0);
}