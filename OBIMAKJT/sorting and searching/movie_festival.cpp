#include<iostream>
#include<vector>
#include <array>
#include<algorithm>
#include <utility>
using namespace std;

int main(){

    int n;
    int a, b;
    cin >> n;

    //vector< pair<int, pair<int, int>> > time(n);
    vector<pair<int, int>> time(n);

    
    for (int i=0; i<n; i++){
        
        cin >> a >> b;
        time[i].first = b;
        time[i].second = a;

    }

    sort(time.begin(), time.end());

    int res = 1;
    int d = time[0].first;

    for (int i=1; i<n; i++){
        if(time[i].second >= d){
            res++;
            d = time[i].first;
        }
    }

    cout << res;

}

// 10
// 404 882
// 690 974

// 525 819
// 461 978

// 201 255
// 457 601
// 699 804
// 832 932


// 795 860

// 800 933


