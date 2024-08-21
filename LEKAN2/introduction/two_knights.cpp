#include <iostream>
#include <vector>

#define SIZE 100000000

using namespace std;
using ll = long long;

ll combinationToBaseTwo(ll a){
    return (a * (a-1)) /2;
}

ll triangle(ll a){
    return ( a*(a+1) ) /2;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // cout << "Starting..." << endl;

    ll n, comb, pos;
    cin >> n;

    for(ll i=1; i<=n; i++) {
        comb = combinationToBaseTwo(i*i);
        pos = 8*triangle(i-2);
        cout << comb - pos << "\n";
    }

    return (0);
}