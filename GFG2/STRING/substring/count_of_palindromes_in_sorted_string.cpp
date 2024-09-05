#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    sort(s.begin(), s.end());

    ll count = 0, ans = 0;
    char past = 0;
    for(size_t i=0; i<s.size(); i++){
        if(s[i] == past) {
            count++;
        }
        else {
            ans += ( count*(count+1) )/2;
            past = s[i]; 
            count = 1;
        }

        if(i == s.size()-1) ans += ( count*(count+1) )/2;
    }

    cout << ans;

    return (0);
}