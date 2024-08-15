#include <iostream>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "Starting..." << "\n";

    string str1, str2;
    cin >> str1 >> str2;
    vector< vector<ll> > dp(str1.size()+1, vector<ll>(str2.size()+1, 0));

    for(size_t i=0; i<dp.size(); i++){
        for(size_t j=0; j<dp[i].size(); j++){
            if(i==0) dp[i][j] = j;
            else if(j==0) dp[i][j] = i;
            else if(str1[i-1] == str2[j-1]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = 1 + min(
                dp[i][j-1],         // insertion
                min( dp[i-1][j],    // removal
                dp[i-1][j-1]        // insertion
            ));
        }
    }

    cout << dp[str1.size()][str2.size()];

    return (0);
}