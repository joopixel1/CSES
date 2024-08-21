#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // cout << "Starting..." << "\n";

    string s1, s2;
    cin >> s1 >> s2;
    vector< vector<ll> > v(s1.size()+1, vector<ll>(s2.size()+1, 0));

    for(size_t i=0; i<v.size(); i++){
        for(size_t j=0; j<v[i].size(); j++){
            if(i==0) v[i][j] = j;
            else if(j==0) v[i][j] = i;
            else if(s1[i-1] == s2[j-1]) v[i][j] = v[i-1][j-1];
            else v[i][j] = min(
                1+v[i-1][j-1], // replace
                min(
                    1+v[i-1][j], // remove
                    1+v[i][j-1]  // add
                ));
        }
    }

    cout << v[s1.size()][s2.size()];    

    return (0);
}