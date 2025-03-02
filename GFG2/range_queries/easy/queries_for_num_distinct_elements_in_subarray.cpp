#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

struct Query{
    ll i, l, r;
};

bool queries_sort_function(const Query& _a, const Query& _b){
    return _a.r < _b.r;
}

void update_bit(vector< ll >& _bit, ll idx, ll val){
    for(; idx<_bit.size(); idx += (idx & -idx)){
        _bit[idx] += val;
    }
}

ll search_bit(vector< ll >& _bit, ll idx){
    ll sum=0;
    for(; idx>0; idx -= (idx & -idx)){
        sum += _bit[idx];
    }
    return sum;
}

void calculate_ans_for_queries_of_num_of_distinct_elements_in_ranges(vector< ll >& _v, vector< Query >& _q, vector< ll >& _ans){
    vector< ll > last_visit(1000000, -1);
    vector< ll > bit(_v.size()+1, 0);
    sort(_q.begin(), _q.end(), queries_sort_function);
    
    auto j = _q.begin();
    for(ll i=0; i<_v.size(); i++){
        if(last_visit[_v[i]] != -1) update_bit(bit, last_visit[_v[i]]+1, -1);


        last_visit[_v[i]] = i;
        update_bit(bit, last_visit[_v[i]]+1, 1);

        for(; j != _q.end() and j->r == i; j++) _ans[j->i] = search_bit(bit, j->r+1) - search_bit(bit, j->l);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cout << "Starting..." << "\n";

    ll n, m;
    cin >> n >> m;
    vector< ll > v(n);
    for(ll i=0; i<n; i++) cin >> v[i];

    ll l, r;
    vector< Query > q;
    for(ll i=0; i<m; i++) {
        cin >> l >> r;
        q.push_back( Query{ i, l, r } );
    }

    vector< ll > ans(m);
    calculate_ans_for_queries_of_num_of_distinct_elements_in_ranges(v, q, ans);
    for(ll i=0; i<m; i++) cout << ans[i] << "\n";

    return (0);
}