/**======================
 * ?        ABOUT
 * @author    : joopixel1
 * @createdOn : 12/20/2023
 * @details   : Fibonacci Numbers Problem
 *========================**/
#include <iostream>
#include <vector>
#include <cassert>

#define GIVEN_MOD 1000000007

using namespace std;

void matrix_multiply(vector<vector<long long>> &a,vector<vector<long long>> &b)
{
    assert( a[0].size() == b.size() );
    assert( a.size() == a[0].size() );
    vector<vector<long long>> c(a.size(), vector<long long>(b[0].size(), 0LL));

    for(size_t i=0; i<a.size(); i++){
        for(size_t j=0; j<b.size(); j++){
            for(size_t k=0; k<b[0].size(); k++){
                c[i][k] = ( c[i][k] + ((a[i][j] * b[j][k]) %GIVEN_MOD) ) %GIVEN_MOD;
            }
        }
    }

    for(size_t i=0; i<a.size(); i++){
        for(size_t j=0; j<a[0].size(); j++){
            a[i][j] = c[i][j];
        }
    }
}

void matrix_power(vector< vector<long long> >& a, long long b){
    vector<vector<long long>> c(a.size(), vector<long long>(a[0].size(), 0));
    for(size_t i=0; i<a.size(); i++) c[i][i] = 1;
    
    while(b){
        if(b&1) matrix_multiply(c, a);
        matrix_multiply(a, a);
        b = b>>1;
    }

    for(size_t i=0; i<a.size(); i++){
        for(size_t j=0; j<a[0].size(); j++){
            a[i][j] = c[i][j];
        }
    }
}
 
int main(){
    long long n, m, k, a, b;
    cin >> n >> m >> k;
    vector<vector<long long>> matrix = vector<vector<long long>>(n, vector<long long>(n, 0));

    for(int i=0; i<m; i++){
        cin >> a >> b;
        matrix[a-1][b-1]++;
    }

    matrix_power(matrix, k);
    cout << matrix[0][n-1];
}








