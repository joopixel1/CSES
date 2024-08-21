/**======================
 * ?        ABOUT
 * @author    : joopixel1
 * @createdOn : 12/20/2023
 * @details   : Fibonacci Numbers Problem
 *========================**/
#include <iostream>
#include <vector>

#define GIVEN_MOD 1000000007

using namespace std;

long long fibonacci(long long n);

vector< vector<long long> >* matrix_multiply(vector< vector<long long> >& a, vector< vector<long long> >& b){
    vector<vector<long long>>* c = new vector<vector<long long>>(2, vector<long long>(2, 0));

    (*c)[0][0] = (a[0][0]*b[0][0] + a[0][1]*b[1][0]) %GIVEN_MOD;
    (*c)[0][1] = (a[0][0]*b[0][1] + a[0][1]*b[1][1]) %GIVEN_MOD;
    (*c)[1][0] = (a[1][0]*b[0][0] + a[1][1]*b[1][0]) %GIVEN_MOD;
    (*c)[1][1] = (a[1][0]*b[0][1] + a[1][1]*b[1][1]) %GIVEN_MOD;

    return c;
}

vector< vector<long long> >* matrix_power(vector< vector<long long> >& a, long long b){
    if(b == 1) return &a;

    if(b & 1) return matrix_multiply(*matrix_power(a, b-1), a);

    else {
        auto c = *matrix_power(a, b>>1);
        return matrix_multiply(c, c);
    }
}

int main(){
    long long n; cin >> n;
    cout << fibonacci(n);
}

// matrix method O(log n)
long long fibonacci(long long n){
    if (n <= 1) return n;

    vector< vector<long long> > base = {{1, 1}, {1, 0}};
    vector< vector<long long> > ans = *matrix_power(base, n-1);

    return ans[0][0];
}

//iterative solution
// int fibonacci(int n){
//     long long i=0, start=0, end=1, current=1;
//     for(; i<n; i++){
//         start=end; end=current;
//         current = (start+end)%GIVEN_MOD;
//     }
//     return start;
// }