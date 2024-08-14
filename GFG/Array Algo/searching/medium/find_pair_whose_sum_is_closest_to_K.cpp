#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "Starting..." << "\n";

    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for(size_t i=0; i<v.size(); i++) cin >> v[i];

    pair<ll, ll> closest = make_pair(v.front(), v.back());
    for (auto a=v.begin(), b=v.end()-1; a!=b; ){
        ll temp = *a + *b;
        ll curr = closest.first + closest.second;

        if(abs(temp-k) < abs(curr-k) ) closest = make_pair(*a, *b);

        if(temp < k) a++;
        else b--;
    }

    cout << closest.first << " " << closest.second;

    return (0);
}