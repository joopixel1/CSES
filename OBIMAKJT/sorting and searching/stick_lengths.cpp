#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){

    int n, mid;
    long long cost=0;
    cin >> n;
    vector<int> lis(n);
    for(int i=0; i<n; i++) cin >> lis[i];
    sort(lis.begin(), lis.end());

    mid = lis[(n-1)/2];
    for (int i=0; i<n; i++) cost += abs(lis[i] - mid);
    cout << cost << endl;

    return (0);
}

int modi(vector<int> li, int m, int n){

    int sol = li[0], high = 1, curr = 1;

    for (int i=1; i<n; i++){
        if(li[i] == li[i-1]) curr++;
        else{ 
            if(curr > high) {
                high = curr;
                sol = li[i-1];
            }
            if(curr == high) {
                if(abs(li[i-1] - m) < abs(sol - m))
                sol = li[i-1];
            }
            curr=0;
            
        }
    }

    return sol;
}