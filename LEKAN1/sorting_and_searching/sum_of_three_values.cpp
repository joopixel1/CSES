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
 
    pair<ll, ll> a, b, c;
    for(auto k=v.begin(); k!=v.end(); k++){
        a = *k;
        ll aim = x-a.first;
        for(auto i=v.begin(), j=(--v.end()); i!=j;){
            ll sum = (*i).first + (*j).first;
            if(i == k) i++;
            else if(j == k) j--;
            else if(sum == aim) {
                b = *i, c = *j;
                goto end;
            }
            else if(sum > aim) j--;
            else i++;
        }
    }
 
    cout << "IMPOSSIBLE";
    return (0);
 
end: 
    vector<ll> s(3);
    s[0] = a.second, s[1] = b.second, s[2] = c.second;
    sort(s.begin(), s.end());
    cout << s[0] << " " << s[1] << " " << s[2];
    return (0);
}