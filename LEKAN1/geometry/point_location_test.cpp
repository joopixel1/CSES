#include <iostream>
#include <complex>

#define x real()
#define y imag()

using namespace std;

typedef long long ll;

template<typename T> istream& operator>>(istream& in, complex<T>& complexNumber) {
    T real, imag;
    if (!(in >> real >> imag)) return in;
    complexNumber = std::complex<T>(real, imag);
    return in;
}

double cross(complex<double> p1, complex<double> p2){
    return (p1.x*p2.y) - (p1.y*p2.x);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
        
    // cout << "Starting..." << "\n";

    int n;
    complex<double> p1, p2, p3;
    
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> p1 >> p2 >> p3;
        double side = cross(p2-p1, p3-p1);
        if(side == 0) cout << "TOUCH" << "\n";
        else if(side > 0) cout << "LEFT" << "\n";
        else cout << "RIGHT" << "\n";
    }
 
    return (0);
}