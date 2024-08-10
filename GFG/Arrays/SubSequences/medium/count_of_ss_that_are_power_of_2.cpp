#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;
using ll = long long;

string s;
set<string> u;

bool isPowerOfTwo(ll i){
    return (i>0) and ((i & (i-1)) == 0);
}

void getSubSequencePowerOfTwo(ll i, const string& sub){
    if(i >= 0){
        if(sub != "" or (sub == "" and (((s[i]-'0')&1) == 0 or s[i] == '1')) ) {
            string temp = s[i]+sub;
            u.insert(temp);
            getSubSequencePowerOfTwo(i-1, temp);
        }
        getSubSequencePowerOfTwo(i-1, sub);
    }
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cout << "Starting..." << "\n";
    
    cin >> s;
    ll ans = 0;
    getSubSequencePowerOfTwo(s.size()-1, "");
    for(auto a: u){
        if(isPowerOfTwo(stoll(a))) ans++;
    }

    cout << ans;
    
    return (0);
}