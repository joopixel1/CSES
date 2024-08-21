#include <vector>
#include <iostream>
#include <set>
#include <cmath>

using namespace std;

int main() {
    int n, m = 0;
    cin >> n;
    vector<int> t(n, -1);

    for(int i=0; i<n; i++){
        cin >> t[i];
        m = max(m, t[i]);
    }

    set<int> first;
    set<int> second;

    for(int i=0; i<m; i++){
        cin >> p;
        s.insert(p);
    }
}