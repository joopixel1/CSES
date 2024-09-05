#include <iostream>
#include <string>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // cout << "Starting..." << "\n";

    string s;
    cin >> s;
    ll maxim=0, count=0, first=0;

    size_t i=0;
    while(i<s.size() and s[i++] != '1') count++;
    first = count;
    
    count = 0;
    for(; i<s.size(); i++){
        if(s[i] == '0') count++;
        else{
            maxim = max(maxim, count);
            count = 0;
        } 
    }

    maxim = max(maxim, first+count);
    cout << maxim;

    return (0);
}