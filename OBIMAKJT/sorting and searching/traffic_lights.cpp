#include <iostream>
#include <set>
using namespace std;

int maxdiff(set<int> p);

int main(){

    int x, n;
    cin >> x >> n;
    set<int> p = {x};

    for (int i=0; i<n; i++){
        int a;
        cin >> a;
        p.insert(a);

        cout << maxdiff(p) << " ";
    }

    return (0);
}

int maxdiff(set<int> p){
    int ans = 0;

    int f = 0;
    for (auto itr : p){
        ans = max(ans, itr-f);
        f = itr;
    } 

    return ans;
}