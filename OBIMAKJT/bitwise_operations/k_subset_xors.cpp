#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, k;
    cin >> n >> k;

    vector< ll > v(n);
    for(ll i=0; i<n; i++) cin >> v[i];

    // find xor bases
    vector< ll > b;
    for(auto i: v){
        for(auto e: b){
            i = min(i, i^e);
        }
        if (i) b.push_back(i);
    }
    sort(b.begin(), b.end());


    // generate k min subset xors using pq
    set< ll > result;
    ll repetition = (1LL << (v.size() - b.size()));
    ll count = (k+repetition-1) / repetition;
    priority_queue< pair< ll, ll >, vector< pair< ll, ll > >, greater< pair< ll, ll > > >pq;
    pq.push({0, 0});
    while((ll)result.size() < count){
        auto [val, next] = pq.top();
        pq.pop();
        result.insert(val);

        if(next < (ll)b.size()){
            pq.push({val ^ b[next], next+1});
            pq.push({val, next+1});
        }
    }

    // print results
    auto p = result.begin();
    for(ll i=1; i<=k; i++){
        cout << *p << " ";
        if(!(i%repetition)) p++;
    }

    return 0;
}
