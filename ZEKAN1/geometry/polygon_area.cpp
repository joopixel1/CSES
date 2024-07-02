#include <iostream>
#include <vector>
#include <complex>
#include <cmath>

#define x real()
#define y imag()

using namespace std;

typedef long long ll;

template<typename T> istream& operator>> (istream& in, complex<T>& num) {
    T real, imag;
    if(!(in >> real >> imag)) return in;
    num = complex<T>(real, imag);
    return in;
}

ll cross(complex<ll> p1, complex<ll> p2){
    return p1.x*p2.y - p2.x*p1.y;
}

ll polygonArea(vector< complex<ll> > pol){
    ll area = 0;
    for(size_t i=0; i<pol.size(); i++){
        area += cross(pol[(i) %pol.size()], pol[(i+1) %pol.size()]);
    }
    return abs(area);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // cout << "Starting..." << "\n";

    ll n;
    vector< complex<ll> > pol;

    cin >> n;
    for(ll i=0; i<n; i++) {
        complex<ll> p;
        cin >> p;
        pol.push_back(p);
    }
    
    cout << polygonArea(pol) << "\n";
 
    return (0);
}