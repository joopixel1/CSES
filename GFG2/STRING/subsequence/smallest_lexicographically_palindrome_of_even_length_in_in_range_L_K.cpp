#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;
using ll = long long;

/**==============================================
 *                COMMENT BLOCK
 *  Approach: The main observation of this problem is if there exists a palindromic subsequence, then it must be of length > 2. 
 * Therefore the resultant subsequence will be a string of length > 2 with the same characters. 
 * Choose the smallest character among those characters which have a frequency greater than 1 in the range [L, R] and print that character twice. 
 * If there is no such character exists then print -1.
 *  
 *  
 *  
 *=============================================**/
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "Starting..." << "\n";

    string s;
    cin >> s;

    map< char, vector<ll> > m;
    for(auto j: "abcdefghijklmnopqrstuvwxyz") m[j].push_back(0);
    string alphabets = "abcdefghijklmnopqrstuvwxyz";

    for(auto i: s){
        for(auto j: alphabets){
            if(i == j) m[j].push_back(m[j].back() + 1);
            else m[j].push_back(m[j].back());
        }
    }
   m.erase(0);

    ll n, l, r;
    cin >> n;
    for(ll i=0; i<n; i++){
        cin >> l >> r;
        string ans = "-1";
        for(auto j: m){
            if(j.second[r+1] - j.second[l] > 1){
                ans = string(2, j.first);
                break;
            }
        }
        cout << ans << "\n";
    }

    return (0);
}