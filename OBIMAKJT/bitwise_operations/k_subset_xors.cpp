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


    // generate k min subset xors using pq
    priority_queue< pair< ll, ll >, vector< pair< ll, ll > >, greater< pair< ll, ll > > >pq;
    set< pair< ll, ll > > s;
    pq.push({0, 0});
    s.insert({0, 0});

    ll repition = (1LL << (v.size() - b.size()));
    ll count = (k+repition-1) / repition;
    set< ll > xors;
    while((ll)xors.size() < count){
        auto [val, next] = pq.top();
        pq.pop();
        xors.insert(val);

        if(next < (ll)b.size()){
            pair< ll, ll > yes = {val ^ b[next], next+1};
            pair< ll, ll > no = {val, next+1};

            if(!s.count(yes)){
                pq.push(yes);
                s.insert(yes);
            }

            if(!s.count(no)){
                pq.push(no);
                s.insert(no);
            }
        }
    }

    // print results
    auto p = xors.begin();
    for(ll i=1; i<=k; i++){
        cout << *p << " ";
        if(!(i%repition)) p++;
    }

    return 0;
}
