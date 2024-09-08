#include <string>
#include <iostream>
#include <unordered_set>

using namespace std;
using ll = long long;

void calc(unordered_set<string>& s, string& s1, string& s2, ll i, ll j, string end){
    if(i == s1.size() and j == s2.size()) {
        s.insert(end);
        return;
    }

    if(j != s2.size()) {
        string n = end+s2[j];
        calc(s, s1, s2, i, j+1, n);
    }
    if(i != s1.size()) {
        string n = end+s1[i];
        calc(s, s1, s2, i+1, j, n);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // cout << "Starting..." << "\n";

    string s1, s2;
    cin >> s1 >> s2;

    unordered_set<string> s;
    calc(s, s1, s2, 0, 0, "");
    for(auto a: s) cout << a << "\n";

    return (0);
}