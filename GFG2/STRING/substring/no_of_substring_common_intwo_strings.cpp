#include <iostream>
#include <string>
#include <map>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // cout << "Starting..." << "\n";

    string a, b, minim, maxim;
    cin >> a >> b;
    if(a.size() < b.size()){
        minim = a;
        maxim = b;
    }
    else{
        minim = b;
        maxim = a;
    }

    map<string, ll> m;
    ll count=0;
    for(size_t i=0; i<minim.size(); i++){
        for(size_t j=1; j<=minim.size()-i; j++){
            string t = minim.substr(i, j);
            if(!m.count(t)) m[t] = (maxim.find(t) != string::npos);
            count += m[t];
        }
    }

    cout << count;

    return (0);
}