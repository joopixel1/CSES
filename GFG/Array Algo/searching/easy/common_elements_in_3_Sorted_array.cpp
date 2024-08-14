#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll a, b, c;
    cin >> a >> b >> c;
    vector<ll> l_a(a), l_b(b), l_c(c);
    for(size_t i=0; i<l_a.size(); i++) cin >> l_a[i];
    for(size_t i=0; i<l_b.size(); i++) cin >> l_b[i];
    for(size_t i=0; i<l_c.size(); i++) cin >> l_c[i];

    for(size_t i=0, j=0, k=0; i<l_a.size() and j<l_b.size() and k<l_c.size();){
        if(l_a[i] == l_b[j] and l_b[j] == l_c[k]) {
            cout << l_a[i] << " ";
            i++, j++, k++;
        }
        else {
            ll minim = min( min(l_a[i], l_b[j]), l_c[k] );
            if(minim == l_a[i]) i++;
            else if (minim = l_b[j]) j++;
            else k++;
        }        
    }

    return (0);
}