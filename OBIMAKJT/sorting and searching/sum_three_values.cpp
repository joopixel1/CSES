#include <iostream>
#include <vector>
#include <utility>
#include<algorithm>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    int n;
    long long sum;
    cin >> n >> sum;
    vector <pair<long long,int>> vals(n);
    for(int i=0; i<n; i++){
        cin >> vals[i].first;
        vals[i].second = i+1;
    }
    sort(vals.begin(), vals.end());

    for(int i=0, j = n-1; i<j;){ 
        long long s=  vals[i].first + vals[j].first;
       
        if(s < sum) {
            bool back = true;
            auto z = lower_bound(vals.begin(), vals.end(), make_pair(sum - s, 0));
            while(*z == vals[i] || *z == vals[j]){
                if(*z == vals.back()){
                    back = false;
                    break;
                }else
                    z++;
            }
            if(s+(*z).first == sum && back){
                cout << vals[i].second << " " << vals[j].second << " " << (*z).second << endl;
                return (0);
            }
            i++;
        }
        
        
        else j--;
    }


    cout << "IMPOSSIBLE" << endl;
    return (0);
}