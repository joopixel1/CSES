#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>

using namespace std;

typedef long long ll;

struct node{
    ll l, r, val;
};

void build_seg_tree(vector< node >& _seg_tree, vector< ll >& _sequence, function< ll (ll, ll) > _func, ll i, ll l, ll r){
    if(l == r){
        _seg_tree[i] = node{ l, r, _sequence[l] };
        return;
    }

    ll mid = (l+r)/2;
    build_seg_tree(_seg_tree, _sequence, _func, i*2+1, l, mid);
    build_seg_tree(_seg_tree, _sequence, _func, i*2+2, mid+1, r);
    _seg_tree[i] = node{ l, r, _func(_seg_tree[i*2+1].val, _seg_tree[i*2+2].val) };
    return;
}

ll search_seg_tree(vector< node >& _seg_tree, function< ll (ll, ll) > _func, ll i, ll l, ll r){
    if(_seg_tree[i].l == l and _seg_tree[i].r == r) return _seg_tree[i].val;

    ll mid = (_seg_tree[i].l+_seg_tree[i].r)/2;
    if(r <= mid) return search_seg_tree(_seg_tree, _func, i*2+1, l, r);
    else if (l > mid) return search_seg_tree(_seg_tree, _func, i*2+2, l, r);
    
    else return _func(
        search_seg_tree(_seg_tree, _func, i*2+1, l, mid),
        search_seg_tree(_seg_tree, _func, i*2+2, mid+1, r)
    );
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cout << "Starting..." << "\n";

    ll n, m;
    cin >> n >> m;

    vector< ll > v(n);
    for(ll i=0; i<n; i++) cin >> v[i];

    vector< node > seg_tree(n*2);
    build_seg_tree(seg_tree, v, lcm<ll, ll>, 0, 0, n-1);
    for(ll i=0; i<2*n; i++) cout << seg_tree[i].l << " " << seg_tree[i].r << " " << seg_tree[i].val << "\n";

    ll l, r;
    for(ll i=0; i<m; i++) {
        cin >> l >> r;
        cout << search_seg_tree(seg_tree, lcm<ll, ll>, 0, l, r) << "\n";
    }

    return (0);
}