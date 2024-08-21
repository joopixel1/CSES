#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){

    int n, s, mid = 1;
    cin >> n >> s;
    vector< pair<int, int>> lis(n);
    vector<int> unlis(n);
    for(int i=0; i<n; i++) {
        cin >> lis[i].first;
        lis[i].second = i+1;
        unlis[i] = lis[i].first;
    }
    sort(lis.begin(), lis.end());
    //for(int i=0; i<n; i++) cout << lis[i].first << " " << lis[i].second << endl;

    for(int i=1; i<n; i++) {
        if(lis[i].second < lis[i-1].second) mid++;
    }
    //cout << mid << endl;

    int a, b, temp;
    vector<int> nexlis(n), mylis(n);
    for(int i=0; i<n; i++) {
        mylis[i] = lis[i].second;
        nexlis[i] = lis[i].second;
    }

    for(int i=0; i<s; i++){

        
        cin >> a >> b;
        int posa = unlis[a-1]-1;
        int posb = unlis[b-1]-1;
        temp = nexlis[posb];
        nexlis[posb] = nexlis[posa];
        nexlis[posa] = temp;
        //for(int i=0; i<n; i++) cout << nexlis[i] << " " << mylis[i] << endl;

        if(abs(posa - posb) > 1){
            if (posb!=0 && mylis[posb] < mylis[posb-1] && nexlis[posb] > nexlis[posb-1]) mid--;
            if (posb!=n-1 && mylis[posb+1] < mylis[posb] && nexlis[posb+1] > nexlis[posb]) mid--;
            if (posa!=0 && mylis[posa] < mylis[posa-1] && nexlis[posa] > nexlis[posa-1]) mid--;
            if (posa!=n-1 && mylis[posa+1] < mylis[posa] && nexlis[posa+1] > nexlis[posa]) mid--;

            if (posb!=0 && mylis[posb] > mylis[posb-1] && nexlis[posb] < nexlis[posb-1]) mid++;
            if (posb!=n-1 && mylis[posb+1] > mylis[posb] && nexlis[posb+1] < nexlis[posb]) mid++;
            if (posa!=0 && mylis[posa] > mylis[posa-1] && nexlis[posa] < nexlis[posa-1]) mid++;
            if (posa!=n-1 && mylis[posa+1] > mylis[posa] && nexlis[posa+1] < nexlis[posa]) mid++;
        }
        else {
          int d= min(posa, posb), e = max(posa, posb);
          if (mylis[d] > mylis[e]) mid--;
          if(mylis[d] < mylis[e]) mid++;
          
          if (d!=0 && mylis[d] < mylis[d-1] && nexlis[d] > nexlis[d-1]) mid--;
          if (d!=0 && mylis[d] > mylis[d-1] && nexlis[d] < nexlis[d-1]) mid++;
          
          if (e!=n-1 && mylis[e+1] < mylis[e] && nexlis[e+1] > nexlis[e]) mid--;
          if (e!=n-1 && mylis[e+1] > mylis[e] && nexlis[e+1] < nexlis[e]) mid++;
        }


        temp = mylis[posb];
        mylis[posb] = mylis[posa];
        mylis[posa] = temp;

        temp = unlis[a-1];
        unlis[a-1] = unlis[b-1];
        unlis[b-1] = temp;

        cout << mid << endl;
    }

    return (0);
}