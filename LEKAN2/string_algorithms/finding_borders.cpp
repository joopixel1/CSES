#include <iostream>
#include <string>
#include <vector>
#include <cassert>

#define PRIME_MAX 1000000007
#define PRIME_CONST 1000003

using namespace std;
using ll = long long;

vector<ll> hashStr;
vector<ll> constPows;

void calculateHashStrAndConstPows(string s){
    hashStr.resize(s.size()), constPows.resize(s.size());
    hashStr[0] = s[0], constPows[0] = 1;
    for(size_t i=1; i<s.size(); i++){
        hashStr[i] = ( ((hashStr[i-1]*PRIME_CONST) %PRIME_MAX) + s[i] ) %PRIME_MAX;
        constPows[i] = (constPows[i-1]*PRIME_CONST) %PRIME_MAX;
    }
}

ll hashSubStr(ll i, ll j){
    assert(j>i);
    if(i == 0) return hashStr[j-1];
    return (hashStr[j-1] - ((hashStr[i-1]*constPows[j-i]) %PRIME_MAX) + PRIME_MAX) %PRIME_MAX;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // cout << "Starting..." << endl;

    string s;
    cin >> s;

    calculateHashStrAndConstPows(s);

    for(size_t i=1; i<s.size(); i++) {
        if(hashSubStr(0, i) == hashSubStr(s.size()-i, s.size())) cout << i << " ";
    }

    return (0);
}