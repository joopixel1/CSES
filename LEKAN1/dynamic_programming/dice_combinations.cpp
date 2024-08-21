#include <iostream>
#include <vector>
#include <queue>

#define PRIME_MAX 1000000007

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // cout << "Starting..." << "\n";

    ll n, curr=0, sum=0;
    cin >> n;
    deque<ll> d;
    for(ll i=1; i<=n; i++){
        if(d.size() < 6){
            curr = (sum+1) %PRIME_MAX;
            sum = (sum+curr) %PRIME_MAX;
            d.push_back(curr);
        }
        else if(d.size() == 6) {
            curr = sum;
            sum = (sum+curr) %PRIME_MAX;
            d.push_back(curr);
        }
        else {
            curr = (sum + PRIME_MAX - d.front()) %PRIME_MAX;
            d.pop_front();
            sum = (curr+curr) %PRIME_MAX;
            d.push_back(curr);
        }
    }

    cout << curr;

    return (0);
}