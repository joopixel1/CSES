#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

ll countSubArray(ll n){
    return (n*(n+1))/2;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "Starting..." << "\n";

    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for(size_t i=0; i<a.size(); i++) cin >> a[i];

    ll sum =0, current =0;
    for(size_t i=0; i<a.size(); i++){
        if(a[i] > k) current++;
        else {
            sum += countSubArray(current);
            current = 0;
        }
    }
    sum += countSubArray(current);
    cout << sum;

    return (0);
}