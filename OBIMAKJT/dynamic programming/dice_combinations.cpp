#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<int, long long> m;
long long leaf(int d);

int main(){

    int n;
    cin >> n;

    cout << leaf(n) << endl;

    return (0);
}

long long leaf(int d){


    if(m.count(d) > 0){
        return m[d];
    }
    else{
        
        long long ans = 0;

        if(d < 0){

        }
        else if(d == 0){
            ans = 1;
        }
        else{
            ans += leaf(d-1) + leaf(d-2) + leaf(d-3);
            ans += leaf(d-4) + leaf(d-5) + leaf(d-6);
            ans %= 1000000007;
        }

        
        m[d] = ans;
        return ans;
    }

}