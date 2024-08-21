#include <iostream>
#include <cmath>
using namespace std;

int main(){

    int n, a=0;
    cin >> n;

    for (int i=2; i<=n; i+=2) {
        cout << i << " ";
        a++;
    }

    int inc=2, start=1;
    while(a < n){

        for (int i=start; i<=n; i+=pow(2, inc)) {
            cout << i << " ";
            a++;
        }

        start+=pow(2, inc-1);
        inc++;
    }



    return (0);
}