#include <iostream>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // cout << "Starting..." << "\n";

    ll a, b, count=0;
    cin >> a >> b;
    while(a!=b){
        if(a<b) b -= a;
        else a -= b;
        count++;
    }

    cout << count;

    return (0);
}