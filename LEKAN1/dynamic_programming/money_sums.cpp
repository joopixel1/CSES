#include <iostream>
#include <vector>
#include <set>

using namespace std;
using ll = long long;

set<ll> s;

// void calculateSumSubSequences(vector<ll>& v, vector<ll>::iterator i, ll sum){
//     if(i != v.end()){
//         s.insert(sum + *i);
//         auto y = i, n = i;
//         calculateSumSubSequences(v, ++n, sum);
//         calculateSumSubSequences(v, ++y, sum + *i);
//     }
// }

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // cout << "Starting..." << "\n";

    ll n;
    cin >> n;
    vector<ll> v(n);
    for(size_t i=0; i<v.size(); i++) cin >> v[i];
    // calculateSumSubSequences(v, v.begin(), 0);
    
    s.insert(0);
    for(size_t i=0; i<v.size(); i++) {
        set<ll> t;
        for(auto a: s) t.insert(a+v[i]);
        s.insert(t.begin(), t.end());
    }
    s.erase(0);

    cout << s.size() << "\n";
    for (auto a: s) cout << a << " ";

    return (0);
}