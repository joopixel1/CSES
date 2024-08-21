#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main(){

    int n = 5;
    //int m[] = {1, 2, 1, 3, 2, 7, 4, 2};
    int b[] = {1, 1, 3, 4, 5};
    map <int,int> s;
    
    //s.reserve(2e5);

    //cout << s[21]<< endl;

    int z=1;
    if(z){
        cout << b[5] << endl;
    }
    else{
        cout << "null" << endl;
    }

    int re=0,temp,c=1,i=1;
    for(;i<=n;i++){
        temp = b[i-1];
        if (s[temp] && s[temp]>=c){
            re=max(i-c,re);
            c=s[temp]+1;
        }
        s[temp]=i;
    }
    re=max(i-c,re);
    cout<<re<<endl;  

    
    return (0);
}