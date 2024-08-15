// #include <iostream>
// #include <vector>
// #include <set>

// using namespace std;
// using ll = long long;

// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);

//     cout << "Starting..." << "\n";

//     ll n, k;
//     cin >> n >> k;
//     vector<ll> v(n);
//     for(size_t i=0; i<v.size(); i++) cin >> v[i];

//     bool ans = false;
//     set<ll> sums;
//     for(size_t i=0; i<v.size(); i++){
//         if(v[i] == k){
//             ans = true;
//             break;
//         }
//         else if(v[i] < k){
//             if(sums.find(k - v[i]) != sums.end()){  
//                 ans = true;
//                 break;
//             } 
//             set<ll> temp(sums);
//             for(auto a : temp){
//                 if(a + v[i] < k) sums.insert(a + v[i]);
//                 else break;
//             }
//             sums.insert(v[i]);
//         }
//     }

//     cout << ans;
    

//     return (0);
// }


// DP SOLUTION
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
    vector<ll> v(n);
    for(size_t i=0; i<v.size(); i++) cin >> v[i];

    vector< vector<ll> > dp(n+1, vector<ll>(k+1, 0));
    dp[0][0] = 1;
    for(size_t i=1; i<dp.size(); i++){
        ll val = v[i-1];
        for(size_t j=0; j<dp[0].size(); j++){
            ll z = j-val;
            dp[i][j] += dp[i-1][j];
            if(z >= 0) dp[i][j] += dp[i-1][z];
        }
    }

    cout << dp[n][k];


    return (0);
}