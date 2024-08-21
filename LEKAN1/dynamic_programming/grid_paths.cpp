#include <iostream>
#include <vector>

#define PRIME_MAX 1000000007;

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // cout << "Starting..." << "\n";

    ll n;
    cin >> n;
    vector< string > v(n);
    for(size_t i=0; i<v.size(); i++){
        string s;
        cin >> s;
        v[i] = s;
    }

    vector< vector<ll> > a(n, vector<ll>(n, 0));
    if(v[0][0] == '.') a[0][0] = 1;
    else a[0][0] = 0;

    for(size_t i=1; i<a.size(); i++){
        for(size_t j=0; j<i; j++) {
            if(v[j][i] == '.'){
                a[j][i] = (a[j][i] + a[j][i-1]) %PRIME_MAX;;
                if(j>0) a[j][i] = (a[j][i] + a[j-1][i]) %PRIME_MAX;;
            }
            else a[j][i] = 0;
        }
        
        for(size_t j=0; j<i; j++) {
            if(v[i][j] == '.'){
                a[i][j] = (a[i][j] + a[i-1][j]) %PRIME_MAX;
                if(j>0) a[i][j] = (a[i][j] + a[i][j-1]) %PRIME_MAX;
            }
            else a[i][j] = 0;
        }

        if(v[i][i] == '.'){
            a[i][i] = (a[i][i] + a[i-1][i]) %PRIME_MAX;
            a[i][i] = (a[i][i] + a[i][i-1]) %PRIME_MAX;
        }
        else a[i][i] = 0;
    }
    
    cout << a[n-1][n-1];

    return (0);
}