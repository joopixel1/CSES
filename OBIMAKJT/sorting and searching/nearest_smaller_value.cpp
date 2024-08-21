#include <iostream>
#include <set>
using namespace std;

int maxist(set< pair<int, int> > li, int u);

int main(){

    int n;
    cin >> n;
    set< pair<int, int> > y;


    for (int i=0; i<n; i++) {
        
        int a;
        cin >> a;

        cout << maxist(y, a) << " ";

        y.insert(make_pair(a,i+1));
        
    }

    cout << endl;
    return (0);
}

int maxist(set< pair<int, int> > t, int u) {
    int sol = 0;
    auto f = t.lower_bound(make_pair(u, 0));

    for(auto i=t.begin(); i!=f; i++){
        sol = max(sol, (*i).second);
    }

    return sol;
}