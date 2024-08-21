
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){

    int n, mid = 1;
    cin >> n;
    vector< pair<int, int>> lis(n);
    for(int i=0; i<n; i++) {
        cin >> lis[i].first;
        lis[i].second = i;
    }
    sort(lis.begin(), lis.end());

    //for(int i=0; i<n; i++) cout << lis[i].first << " " << lis[i].second << endl;

    for(int i=1; i<n; i++) {
        if(lis[i].second < lis[i-1].second) mid++;
    }

    cout << mid << endl;
    return (0);
}