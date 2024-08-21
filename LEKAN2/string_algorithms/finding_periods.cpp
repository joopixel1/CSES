#include <iostream>
#include <vector>

#define PRIME_MAX 1000000007
#define PRIME_CONST 1000003

using namespace std;
using ll = long long;

vector<ll> sumStr;
vector<ll> hashStr;
vector<ll> powHashStr;
vector<ll> constPows;

ll power_mod(ll base, ll exponent, ll mod){
    ll ans = 1;
    while(exponent){
        if(exponent&1) ans = (ans*base) %mod; 
        base = (base*base) %mod;
        exponent >>= 1;
    }
    return ans;
}

ll triangle(ll n){
    ll half = power_mod(2, PRIME_MAX-2, PRIME_MAX);
    return ( ( (n*(n+1)) %PRIME_MAX ) * half ) %PRIME_MAX;
}

void calculateVectors(string s){
    sumStr.resize(s.size()), hashStr.resize(s.size()), powHashStr.resize(s.size()), constPows.resize(s.size());
    sumStr[0] = hashStr[0] = s[0], powHashStr[0] = s[0], constPows[0] = 1;
    for(size_t i=1; i<s.size(); i++){
        sumStr[i] = (sumStr[i-1] + s[i]) %PRIME_MAX;
        hashStr[i] = ( hashStr[i-1] + (((i+1) * s[i]) %PRIME_MAX) ) %PRIME_MAX;
        powHashStr[i] = ( ((powHashStr[i-1] * PRIME_CONST) %PRIME_MAX) + s[i] ) %PRIME_MAX;
        constPows[i] = (constPows[i-1] * PRIME_CONST) %PRIME_MAX;
    }
}

ll calculatePowHashStr(ll i, ll j){
    if(i>=j) return -1;
    if(i==0) return powHashStr[j-1];
    return (powHashStr[j-1] - ((powHashStr[i-1] * constPows[j-i]) %PRIME_MAX) + PRIME_MAX) %PRIME_MAX;
}

ll calculateSumStr(ll i, ll j){
    if(i>=j) return -1;
    if(i == 0) return sumStr[j-1];
    return (sumStr[j-1] - sumStr[i-1] + PRIME_MAX) %PRIME_MAX;
}

ll calculateHashStr(ll i, ll j){
    if(i>=j) return -1;
    if(i==0) return hashStr[j-1];
    else return ( ((hashStr[j-1] - hashStr[i-1] + PRIME_MAX) %PRIME_MAX) - ((j-i)*calculateSumStr(i, j) %PRIME_MAX) + PRIME_MAX ) %PRIME_MAX;
}

ll calculateMultipleHashStr(ll size, ll multiple){
    ll temp1 = triangle(multiple-1);
    ll temp2 = calculateSumStr(0, size);
    ll temp3 = calculateHashStr(0, size);
    return ( 
        ( (size*temp1) %PRIME_MAX * temp2 ) %PRIME_MAX
         + (multiple*temp3) %PRIME_MAX 
    ) %PRIME_MAX;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // cout << "Starting..." << endl;

    string s;
    cin >> s;
    calculateVectors(s);

    for(size_t i=1; i<=s.size(); i++){
        ll multiple = s.size()/i;
        ll end = multiple*i;
        ll temp1 = calculateHashStr(0, end);
        ll temp2 = calculateMultipleHashStr(i, multiple);
        ll temp3 = calculatePowHashStr(end, s.size());
        ll temp4 = calculatePowHashStr(0, s.size()-end);
        if(
            temp2 == temp1
            and temp4 == temp3
        ) cout << i << " ";
    }

    return (0);
}