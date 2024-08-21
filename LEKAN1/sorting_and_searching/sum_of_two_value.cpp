#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
 
using namespace std;
using ll = long long;
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    // cout << "Starting..." << "\n";
 
    ll n, x, t;
    cin >> n >> x;
    vector< pair<ll, ll> > v(n);
    for(size_t i=0; i<v.size(); i++) {
        cin >> t;
        v[i] = make_pair(t, i+1);
    }
    sort(v.begin(), v.end());
 
    pair<ll, ll> a, b;
    for(auto i=v.begin(), j=(--v.end()); i!=j;){
        ll sum = (*i).first + (*j).first;
        if(sum == x) {
            a = *i, b = *j;
            goto end;
        }
        else if(sum > x) j--;
        else i++;
    }
 
    cout << "IMPOSSIBLE";
    return (0);
 
end: 
    vector<ll> s(2);
    s[0] = a.second, s[1] = b.second;
    sort(s.begin(), s.end());
    cout << s[0] << " " << s[1];
    return (0);
}