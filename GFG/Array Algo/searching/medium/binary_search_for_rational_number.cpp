#include <iostream>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

struct Rational{
    ll p;
    ll q;

    bool operator==(const Rational& other) const {
        return p*other.q == other.p*q;
    }

    bool operator<(const Rational& other) const {
        return p*other.q < other.p*q;
    }

    bool operator>(const Rational& other) const {
        return p*other.q > other.p*q;
    }

    friend istream& operator>>(istream& in, Rational& r) {
        try{
            string s;
            in >> s;
            auto div = s.find('/');
            
            r.p = stoll(s.substr(0, div));
            r.q = stoll(s.substr(div+1));
        }catch(const exception& e){}
        return in;        
    }
};

vector<Rational> v;

ll search(Rational a, ll i, ll j){
    ll mid = (i+j)/2;
    if(v[mid] == a) return mid;
    else if(a < v[mid]) {
        if(mid-1 < i) return -1;
        else return search(a, i, mid-1);
    }
    else{
        if(mid+1 > j) return -1;
        else return search(a, mid+1, j);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "Starting..." << "\n";

    ll n;
    Rational k;
    cin >> n >> k;
    v.resize(n);
    for(size_t i=0; i<v.size(); i++) cin >> v[i];

    cout << search(k, 0, v.size()-1);

    return (0);
}






