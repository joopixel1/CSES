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

    pair<ll, ll> a, b, c, d;
    set< pair<ll, ll> > se;
    for(auto k=v.begin(); k!=v.end()-3; k++){
        a = *k;
        ll minor = x-a.first;
        for(auto l=k+1; l!=v.end()-2; l++){
            if(l != k){
                b = *l;
                ll aim = minor-b.first;
                // if(se.count(make_pair(b.first, a.first)) | se.count(make_pair(a.first, b.first))) break;
                for(auto i=l+1, j=v.end()-1; i!=j;){
                    ll sum = (*i).first + (*j).first;
                    if(i==k or i==l) i++;
                    else if(j==k or j==l) j--;
                    else if(sum == aim) {
                        c = *i, d = *j;
                        goto end;
                    }
                    else if(sum > aim) j--;
                    else i++;
                }
                // se.insert(make_pair(a.first, b.first));
            }
        }
    }

    cout << "IMPOSSIBLE";
    return (0);

end: 
    vector<ll> s(4);
    s[0] = a.second, s[1] = b.second, s[2] = c.second, s[3] = d.second;;
    sort(s.begin(), s.end());
    cout << s[0] << " " << s[1] << " " << s[2] << " " << s[3];
    return (0);
}