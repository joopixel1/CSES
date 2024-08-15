#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

bool comparePairs(const pair<ll, ll>& a, const pair<ll, ll>& b){
    return (a.first == b.first) ? a.second < b.second : a.first > b.first;
}
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "Starting..." << "\n";

    ll n, s, t;
    cin >> n;
    vector< pair<ll, ll> > v(n);
    for(size_t i=0; i<v.size(); i++) {
        cin >> s >> t;
        v[i] = make_pair(t, s);
    }
    sort(v.begin(), v.end(), comparePairs);

    ll profit = 0;
    for(size_t i=0, j=1; i<v.size(); i++){
        if(v[i].second >= j) j++, profit += v[i].first;
    }

    cout << profit;

    return (0);
}