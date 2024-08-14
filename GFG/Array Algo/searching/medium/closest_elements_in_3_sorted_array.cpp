#include <iostream>
#include <vector>
#include <tuple>
#include <climits>

using namespace std;
using ll = long long;

ll cost(ll a, ll b, ll c){
    ll minim = min( a, min(b, c) );
    ll maxim = max( a, max(b, c) );
    return abs(maxim-minim);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll a, b, c;
    cin >> a >> b >> c;
    vector<ll> l_a(a), l_b(b), l_c(c);
    for(size_t i=0; i<l_a.size(); i++) cin >> l_a[i];
    for(size_t i=0; i<l_b.size(); i++) cin >> l_b[i];
    for(size_t i=0; i<l_c.size(); i++) cin >> l_c[i];


    tuple<ll, ll, ll> closest = make_tuple(l_a.front(), l_b.front(), l_c.front());
    for(size_t i=0, j=0, k=0; true;){
        if (i==l_a.size()-1 and j==l_b.size()-1 and k==l_c.size()-1) break;
        
        ll cost_a = (i == l_a.size()-1) ? LLONG_MAX : cost(l_a[i+1], l_b[j], l_c[k]);
        ll cost_b = (j == l_b.size()-1) ? LLONG_MAX : cost(l_a[i], l_b[j+1], l_c[k]);
        ll cost_c = (k == l_c.size()-1) ? LLONG_MAX : cost(l_a[i], l_b[j], l_c[k+1]);
        ll minim = min( cost_c, min(cost_a, cost_b) );

        if(cost_a == minim) i++;
        else if(cost_b == minim) j++;
        else k++; 
        
        ll cost_closest = cost(get<0>(closest), get<1>(closest), get<2>(closest));
        ll cost_current = cost(l_a[i], l_b[j], l_c[k]);
        if(cost_current < cost_closest) closest = make_tuple(l_a[i], l_b[j], l_c[k]);
    }

    cout << get<0>(closest) << " " <<  get<1>(closest) << " " << get<2>(closest);

    return (0);
}