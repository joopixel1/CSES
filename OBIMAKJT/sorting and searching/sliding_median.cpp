#include <iostream>
#include <set>
#include <vector>
using namespace std;

int maxist(set< pair<int, int> > li, int u);

int main(){

    int n, k;
    cin >> n >> k;
    multiset<int> x;
    vector<int> y;
    for (int i=0; i<k; i++) {
        int a;
        cin >> a;
        x.insert(a);
        y.push_back(a);
    }
    auto med = next(x.begin(), (int)((x.size()-1) / 2));


    for (int i=0; i<n-k+1; i++) {
        
        cout << *med << " ";

        x.erase(x.find(y[0]));

        int a;
        cin >> a;
        x.insert(a);
        
    }

    cout << endl;
    return (0);
}