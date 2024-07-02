#include <iostream>
#include <complex>
#include <vector>
#include <algorithm>

#define x real()
#define y imag()

using namespace std;

typedef long long ll;
typedef struct point{
    complex<ll> p;
    ll radSq;

    bool operator< (const point& other) const{ // const ensures that this function does not modify any oof the variables in this struct
        return radSq < other.radSq;
    }
} point_t;

ll sq(ll real, ll imag){
    return (real*real) + (imag*imag);
}

ll sq(point_t p, point_t q){
    return sq(p.p.x-q.p.x, p.p.y-q.p.y);
}

istream& operator>>(istream& in, point_t& num){
    ll real, imag;
    if(!(in >> real >> imag)) return in;
    num = {complex<ll>(real, imag), sq(real, imag)};
    return in;
}

/**---------------------------------------------------------------------
 * *       `                INFO
 * What is the idea: 
 * The idea here is that the distance between two points must be greater
 * than their distance if they were on a strainght vector from the origin
 *  
 *  
 *----------------------------------------------------------------------**/
double perpAbsDist(point_t p, point_t q){
    return pow( abs(pow(p.radSq, 0.5) - pow(q.radSq, 0.5)), 2);
}

ll findMin(vector<point_t> arr){
    ll minDist = sq(arr[0], arr[1]);
    for(size_t i=0; i<arr.size(); i++){
        for (size_t j = i + 1; j < arr.size(); j++) {
            if(perpAbsDist(arr[j], arr[i]) > minDist) break;
            minDist = min(minDist, sq(arr[i], arr[j]));
        }
    }
    return minDist;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // cout << "Starting..." << "\n";

    ll n;
    vector<point_t> arr;

    cin >> n;
    for(ll i=0; i<n; i++) {
        point_t p;
        cin >> p;
        arr.push_back(p);
    }

    sort(arr.begin(), arr.end());

    cout << findMin(arr) << "\n";

    return (0);
}