#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){

    int n;
    cin >> n;
    vector<pair<int, int>> task(n);
    for (int i=0; i<n; i++) cin >> task[i].first >> task[i].second;
    sort(task.begin(), task.end());

    long long reward = 0, time = 0;

    for (int i=0; i<n; i++){
        time += (long long) task[i].first;
        reward += (long long) (task[i].second - time);
    }

    cout << reward;
    
    return (0);
}


