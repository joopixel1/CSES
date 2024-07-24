#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // cout << "Starting..." << endl;

    ll n, x;
    cin >> n >> x;

    vector<ll> p(n);
    for(int i=0; i<n; i++) cin >> p[i];
    sort(p.begin(), p.end());

    int count=0, i=0, j=p.size()-1;
    while(j>=i){
        if(p[i]+p[j] <= x) i++; 
        j--, count ++;
    }

    cout << count;

    return (0);
}