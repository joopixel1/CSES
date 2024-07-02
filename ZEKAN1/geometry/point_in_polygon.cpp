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

ll dot(complex<ll> p, complex<ll> q){
    return p.x*q.x + p.y*q.y; 
}

ll cross(complex<ll> p, complex<ll> q){
    return p.x*q.y - p.y*q.x; 
}

bool inDisk(pair<complex<ll>, complex<ll>> s, complex<ll> p){
    return dot(s.first-p, s.second-p) <= 0;
}

double orient(complex<ll> a, complex<ll> b, complex<ll> c){
    return cross(b-a, c-a);
}

bool onSegment(pair<complex<ll>, complex<ll>> s, complex<ll> p){
    return inDisk(s, p) and orient(s.first, s.second, p) == 0;
}

bool above(complex<ll> p, complex<ll> z){
    return p.y >= z.y;
}

bool rayCrossing(pair<complex<ll>, complex<ll>> s, complex<ll> p){
    return (above(s.first, p) - above(s.second, p)) * orient(p, s.second, s.first) > 0;
}

ll pollInPolygon(complex<ll> p, vector< complex<ll> > pol){
    ll numCrossings=0;
    for(size_t i=0; i<pol.size(); i++){
        if(onSegment({pol[(i) %pol.size()], pol[(i+1)  %pol.size()]}, p)) return -1;
        numCrossings += rayCrossing({pol[(i) %pol.size()], pol[(i+1)  %pol.size()]}, p);
    }
    return numCrossings & 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // cout << "Starting..." << "\n";

    ll n, m;
    vector< complex<ll> > pol;

    cin >> n >> m;

    for (ll i=0; i<n; i++){
        complex<ll> p;
        cin >> p;
        pol.push_back(p);
    }

    for (ll i=0; i<m; i++){
        complex<ll> p;
        cin >> p;

        switch(pollInPolygon(p, pol)){
            case 1: 
                cout << "INSIDE" << "\n";
                break;
            case 0:
                cout << "OUTSIDE" << "\n";
                break;
            case -1:
                cout << "BOUNDARY" << "\n";
                break;
        }
    }


    return (0);
}