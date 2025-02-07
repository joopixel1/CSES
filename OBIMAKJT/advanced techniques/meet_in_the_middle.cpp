#include <iostream>
#include <vector>
#include <climits>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    // cout << "Starting...";

    int n, k;
    cin >> n >> k;

    string s;
    vector<ll> v;
    for(int i=0; i<n; i++){
        cin >> s;
        v.push_back(stoll(s, nullptr, 2));
    }

    int minim = INT_MAX;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            int t = v[i] ^ v[j];
            minim = min(minim, __builtin_popcount(t));
        }
    }

    cout << minim;

    return 0;
}