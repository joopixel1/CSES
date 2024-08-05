#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "Starting..." << "\n";

    ll n;
    cin >> n;
    vector<ll> a(n);
    for(size_t i=0; i<a.size(); i++) cin >> a[i];

    auto start = a.begin();
    while(*start <= *(start+1)) start++;
    auto end = start+1;
    while(end != a.end() and *end <= *(end-1) ) end++;

    reverse(start, end);
    for(size_t i=0; i<a.size(); i++) cout << a[i] << " ";
    
    return (0);
}