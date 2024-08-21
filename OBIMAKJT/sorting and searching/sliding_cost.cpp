#include <iostream>
#include <vector>
using namespace std;


int main(){

    int n, k;
    double mean=0;
    cin >> n >> k;
    vector<int> x(n);
    for (int i=0; i<n; i++) {
        int a; cin >> a;
        x[i] = a;
        mean += ((double)a/k);
    }

    cout << mean << endl;
    for (int i=0; i<n; i++) cout << x[i];

    int ans=0, sum=0;
    for(int i=0; i<n; i++){
        sum+=x[i];
        if(sum>=mean){
            ans=max(sum, ans);
            sum=0;
        }
    }
    ans=max(sum, ans);
    
    cout << ans;

    
}