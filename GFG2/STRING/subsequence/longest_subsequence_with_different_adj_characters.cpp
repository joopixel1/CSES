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
    char c = s[0];
    ll count = 1;
    for(size_t i=1; i<s.size(); i++){
        if(s[i] != c){
            c = s[i];
            count++;
        }
    }

    cout << count;
    
    return (0);
}