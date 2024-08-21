#include <iostream>
#include <vector>
#include <array>
#include<algorithm>
using namespace std;

int main(){

    int n, sum;
    cin >> n >> sum;
    vector <pair<int,int>> vals(n);
    for(int i=0; i<n; i++){
        cin >> vals[i].first;
        vals[i].second = i+1;
    }
    sort(vals.begin(), vals.end());

    for(int i=0, j = n-1; i<j;){ 
        int s= vals[i].first + vals[j].first;
        if(sum == s){
            cout << vals[i].second << " " << vals[j].second << endl;
            return (0);
        }
        if(s < sum) i++;
        else j--;
    }

    cout << "IMPOSSIBLE" << endl;
    return (0);
}