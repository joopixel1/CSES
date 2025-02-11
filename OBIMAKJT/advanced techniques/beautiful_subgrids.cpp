#include <iostream>
#include <vector>
#include <climits>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    // cout << "Starting...";

    int n;
    cin >> n;

    string s;
    vector<string> v;
    for(int i=0; i<n; i++){
        cin >> s;
        v.push_back(s);
    }

    int minim = INT_MAX;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            int t = similar(v[i], v[j]);
            minim = min(minim, __builtin_popcount(t));
        }
    }

    cout << minim;

    return 0;
}