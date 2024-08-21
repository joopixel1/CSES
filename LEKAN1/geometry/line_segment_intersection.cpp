#include <iostream>
#include <complex>
#include <cmath>

#define x real()
#define y imag()

using namespace std;

typedef long long ll;

template<typename T> istream& operator>> (istream& in, complex<T>& num){
    T real, imag;
    if(!(in >> real >> imag)) return in;
    num = complex<T>(real, imag);
    return in;
}

double cross(complex<double> a, complex<double> b){
    return a.x*b.y - a.y*b.x;
}

double dot(complex<double> a, complex<double> b){
    return a.x*b.x + a.y*b.y;
}

double orient(complex<double> a, complex<double> b, complex<double> c){
    return cross(b-a, c-a);
}

bool inDisk(pair<complex<double>, complex<double>> s, complex<double> p){
    return dot(s.first-p, s.second-p) <= 0;
}

bool onSegment(pair<complex<double>, complex<double>> s, complex<double> p){
    return((abs(orient(s.first, s.second, p) - 0) <= 1e-9) and inDisk(s, p));
}

bool segmentIntersect(pair<complex<double>, complex<double>> s1, pair<complex<double>, complex<double>> s2){
    pair<double, double> o1, o2;
    o1.first = orient(s1.first, s1.second, s2.first);
    o1.second = orient(s1.first, s1.second, s2.second);
    o2.first = orient(s2.first, s2.second, s1.first);
    o2.second = orient(s2.first, s2.second, s1.second);

    if((o1.first*o1.second < 0) and (o2.first*o2.second < 0)) return true;

    if(onSegment(s1, s2.first) or onSegment(s1, s2.second) or onSegment(s2, s1.first) or onSegment(s2, s1.second)) return true;
    
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // cout << "Starting..." << "\n";

    int n;
    complex<double> p1, p2, p3, p4;

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> p1 >> p2 >> p3 >> p4;
        if(segmentIntersect({p1, p2}, {p3, p4})) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
 
    return (0);
}