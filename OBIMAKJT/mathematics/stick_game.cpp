#include <vector>
#include <set>
#include <iostream>

using namespace std;

int main() {
    int n, k, p;
    cin >> n >> k;
    vector<int> ans(n, -1);
    set<int> s;

    for(int i=0; i<k; i++){
        cin >> p;
        s.insert(p);
    }

    for(int i=1; i<=n; i++){
        if(s.count(i)) {
            ans[i-1] = 1;
            continue;
        }

        for(auto j: s){
            if((i-j-1 >= 0) and (i-j-1 < ans.size()) and (ans[i-j-1] == 0)) ans[i-1] = 1;
        }

        if(ans[i-1] == -1) ans[i-1] = 0;
    }

    for(auto a: ans){
        if(a) cout << 'W';
        else cout << 'L';
    }
}