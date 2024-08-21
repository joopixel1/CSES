#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // cout << "Starting..." << "\n";

    string s;
    cin >> s;
    ll count=0;
    while (s != "0"){
        string a(1, *max_element(s.begin(), s.end()));
        ll val = stoll(s) - stoll(a);
        s = to_string(val);
        count ++;
    }

    cout << count;

    return (0);
}