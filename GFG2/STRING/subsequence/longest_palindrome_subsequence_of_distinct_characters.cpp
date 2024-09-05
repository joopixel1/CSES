#include <iostream>
#include <string>
#include <set>
#include <map>
#include <vector>

using namespace std;
using ll = long long;

void createLetterArray(map<char, pair< vector<ll>, pair<ll, ll> > >& m, string& s, char c){
    vector<ll> v(s.size());
    ll past=0, count = 0, a=0, b=0;
    for(size_t i=0; i<v.size(); i++){
        if(s[i] == c) count++;
        if(past == 0 and count == 1) a=i;
        if(count == past+1) b = i;
        v[i] = past = count;
    }
    m[a] = make_pair( v, make_pair(a, b) );
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // cout << "Starting..." << "\n";

    string s;
    cin >> s;

    set<char> characters;
    for(auto a: s) characters.insert(a);

    map<char, pair< vector<ll>, pair<ll, ll> > > m;
    for(auto a: characters) createLetterArray(m, s, a);

    ll maxim=0;
    for(auto a: characters){
        vector<ll> theta = m[a].first;
        pair<ll, ll> bound = m[a].second;
        if(bound.first == 0 || bound.second == s.size()-1) continue;

        ll count = theta[s.size()-1];
        for(auto b: characters){
            if(b == a) continue;
            vector<ll> pheta = m[b].first;
            maxim = max(maxim, count + min(pheta[bound.first], pheta[s.size()-1] - pheta[bound.second]));
        }
    }

    cout << maxim;
    
    return (0);
}