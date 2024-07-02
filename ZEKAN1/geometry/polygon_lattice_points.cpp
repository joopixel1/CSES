#include <iostream>
#include <vector>
#include <complex>
#include <cmath>

#define x real()
#define y imag()

using namespace std;

typedef long long ll;

template<typename T> istream& operator>>(istream& in, complex<T>& num){
    T real, imag;
    if(!(in >> real >> imag)) return in;
    num = complex<T>(real, imag);
    return in;
}

ll cross(complex<ll> p, complex<ll> q){
    return p.x*q.y - p.y*q.x;
}

ll gcd(ll a, ll b){
    while (b != 0) {
        ll temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

pair<ll, ll> noLatticeOnBoundaryAndArea2(vector< complex<ll> > pol){
    ll area = 0, boundaryLattice = 0;
    for(size_t i=0; i<pol.size(); i++){
        // AREA
        area += cross(pol[(i) %pol.size()], pol[(i+1) %pol.size()]);

        // BOUNDARY LATTICE
        boundaryLattice += gcd(abs(pol[(i) %pol.size()].x - pol[(i+1) %pol.size()].x), abs(pol[(i) %pol.size()].y - pol[(i+1) %pol.size()].y));
    }
    return make_pair(boundaryLattice, abs(area));
}

/**----------------------------------------------
 * *                   INFO
 *   PICK'S THEOREM: 2A = 2i + b -2
 *---------------------------------------------**/
ll noLatticeInInterior(ll b, ll a2){
    return (a2 - b + 2) / 2;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // cout << "Starting..." << "\n";
    ll n;
    vector< complex<ll> > pol;

    cin >> n;
    for(ll i=0; i<n; i++){
        complex< ll> p;
        cin >> p;
        pol.push_back(p);
    }

    pair<ll, ll> boundaryAndArea = noLatticeOnBoundaryAndArea2(pol);
    ll boundary = boundaryAndArea.first, area = boundaryAndArea.second;
    ll interior = noLatticeInInterior(boundary, area);

    cout << interior << " " << boundary << "\n";
 
    return (0);
}