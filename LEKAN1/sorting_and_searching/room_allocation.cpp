#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

typedef struct planner{
    ll b, a, i, r;
} planner_t;

bool compareFinishing(const planner_t& i, const planner_t& j) {
    return (i.b == j.b) ? i.a < j.a : i.b < j.b;
}

bool compareIndexing(const planner_t& i, const planner_t& j) {
    return i.i < j.i;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // cout << "Starting..." << "\n";

    ll n, a, b;
    cin >> n;
    vector< planner_t > v(n);
    for(ll i=0; i<n; i++){
        cin >> a >> b;
        v[i] = {b, a, i, 0};
    }
    sort(v.begin(), v.end(), compareFinishing);

    vector<ll> ans;
    for(size_t i=0; i<v.size(); i++){
        auto it = lower_bound(ans.begin(), ans.end(), v[i].a+1);
        if(it == ans.end()) {
            ans.push_back(v[i].b);
            v[i].r = ans.size();
        }
        else {
            *it = v[i].b;
            v[i].r = it - ans.begin() + 1;
        }
    }

    cout << ans.size() << "\n";
    sort(v.begin(), v.end(), compareIndexing);
    for(size_t i=0; i<v.size(); i++) cout << v[i].r << " ";

    return (0);
}