#include <iostream>
#include <string>
#include <cassert>
#include <vector>

#define PRIME_MAX 1000000007
#define PRIME_CONST 1000003

using namespace std;
using ll = long long;

/**----------------------------------------------
 * *                   INFO
 *   
 *   This function calculates the hash values and the power of the prime constant for the given string.
 * 
 * Using polynomial hashing, we can calculate the hash value of any substring of a string s in O(1) time after an O(n) time preprocessing. 
 * The idea is to construct an array h such that h[k] contains the hash value of the prefix s[0...k]. 
 * The array values can be recursively calculated as follows: h[0] = s[0],
 * h[k] = (h[k 1]A s[k]) mod B
 * 
 *  In addition, we construct an array p where p[k] Ak mod B: p[0] = 1
 * p[k] = (p[k 1]A) mod B.
 * 
 * @param s: The input string for which hash values and constants are calculated.
 * @param arr: The array that will store the hash values for each prefix of the string.
 * @param consts: The array that will store the powers of the prime constant.   
 *
 *---------------------------------------------**/
inline void calculateHashArray(string s, vector<ll>& arr, vector<ll>& consts){
    arr[0] = s[0], consts[0] = 1;
    for(size_t i=1; i<s.size(); i++){
        arr[i] = ( (arr[i-1]*PRIME_CONST) %PRIME_MAX + s[i] ) %PRIME_MAX;
        consts[i] = (consts[i-1]*PRIME_CONST) %PRIME_MAX;
    }
}

/**----------------------------------------------
 * *                   INFO
 * 
 * This function calculates the hash value for a substring of the input string.
 * 
 * After this, the hash value of any substring s[a...b] can be calculated in O(1) time using the formula
 *  = (h[b] - h[a 1]p[b a 1]) modB assuming that a > 0. 
 * If a 0, the hash value is simply h[b].
 *  
 * @param i: The starting index of the substring (inclusive).
 * @param j: The ending index of the substring (exclusive).
 * @param arr: The array that contains hash values for each prefix of the string.
 * @param consts: The array that contains the powers of the prime constant.
 * @return: The hash value of the substring from index i to j-1.   
 *
 *---------------------------------------------**/
inline ll hashSubString(string s, ll i, ll j, vector<ll>& arr, vector<ll>& consts){
    assert(j>i);
    if(i == 0) return arr[j-1];
    return ( arr[j-1] - ((arr[i-1]*consts[j-i]) %PRIME_MAX) + PRIME_MAX) %PRIME_MAX;
    return 1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // cout << "Starting..." << endl;

    string str, pattern;
    cin >> str >> pattern;

    vector<ll> hashStr(str.size()), hashPattern(pattern.size()), constantPowers(str.size());
    calculateHashArray(pattern, hashPattern, constantPowers);
    calculateHashArray(str, hashStr, constantPowers);

    
    ll ans = 0, temp, patternHashCode = hashPattern.back();
    if(str.size() >= pattern.size()) {
        for(size_t i=0; i<=str.size()-pattern.size(); i++) {
            // ans += (hashSubString(str, i, i+pattern.size(), hashStr, constantPowers) == hashPattern.back());
            // function call to costly for compiler, so I had to manually inline the code. 
            // You can check the comment of the function above for what is happening here.
            if(i == 0) temp = hashStr[i+pattern.size()-1];
            else temp = ( hashStr[i+pattern.size()-1] - ((hashStr[i-1]*constantPowers[i+pattern.size()-i]) %PRIME_MAX) + PRIME_MAX) %PRIME_MAX;
            ans += (temp == patternHashCode);
        }
    }

    cout << ans;

    return (0);
}