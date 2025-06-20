#include <iostream>
#include <bit>

using namespace std;
using ull = unsigned long long;

// 0-indexed
ull get_lmb(ull n){ // 2 : 8
    ull m = 0; // 0 : 0
    n >>= 1; // 1 : 4
    while(n){  
        m++; // 1 : 1,2,3 
        n >>= 1; // 0 : 2,1,0
    }
    return m; // 1 : 3
}

ull counting_bits(ull n){ // 2 : 8
    if (n == 0) return 0;
    if (n == 1) return 1;

    ull lmb = get_lmb(n); // 1 : 3
    ull part1 = lmb * (1ULL << (lmb-1)); // 1 : 12
    ull remain = n + 1 - (1ULL << lmb); // 1 : 1
    ull part2 = remain ? counting_bits(remain-1) : 0; // 0 : 0
    return part1 + remain + part2; // 2 : 13
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ull n;
    cin >> n;

    cout << counting_bits(n) << '\n';

    return 0;
}