#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int  main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // cout << "Starting..." << "\n";

    ll n, m, s, t;
    cin >> n >> m;
    vector< pair<ll, ll> > v(n), u(n);
    for(size_t i=0; i<v.size(); i++){
        cin >> t;
        v[i] = make_pair(t, i+1);
        u[i] = make_pair(t, i+1);
    }

    sort(v.begin(), v.end());
    ll ans = 1;
    for(size_t i=1; i<v.size(); i++) ans += (v[i].second < v[i-1].second);

    for(ll i=0; i<m; i++){
        cin >> s >> t;

        ll temp1 = 0;
        ll ind_s = u[s-1].first;
        if(ind_s>1) temp1 += (v[ind_s-1].second < v[ind_s-2].second);
        if(ind_s<n) temp1 += (v[ind_s].second < v[ind_s-1].second);

        ll ind_t = u[t-1].first;
        if(ind_t>1 and (ind_t-1)!=ind_s) temp1 += (v[ind_t-1].second < v[ind_t-2].second);
        if(ind_t<n and (ind_t+1)!=ind_s) temp1 += (v[ind_t].second < v[ind_t-1].second);

        v[ind_t-1].second = s;
        v[ind_s-1].second = t;

        ll temp2 = 0;
        if(ind_s>1) temp2 += (v[ind_s-1].second < v[ind_s-2].second);
        if(ind_s<n) temp2 += (v[ind_s].second < v[ind_s-1].second);

        if(ind_t>1 and (ind_t-1)!=ind_s) temp2 += (v[ind_t-1].second < v[ind_t-2].second);
        if(ind_t<n and (ind_t+1)!=ind_s) temp2 += (v[ind_t].second < v[ind_t-1].second);

        swap(u[t-1], u[s-1]);
        ans += (temp2 - temp1);
        cout << ans << "\n";
    }

    return (0);
}