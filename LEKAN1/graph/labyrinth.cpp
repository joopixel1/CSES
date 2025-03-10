#include <iostream>
#include <vector> 
#include <queue>
#include <tuple>

using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // cout << "Starting..." << "\n";

    ll n, m;
    cin >> n >> m;

    vector< string > v;
    for(ll i=0; i<n; i++){
        string s;
        cin >> s;
        v.push_back(s);
    }
    vector< vector< char > > visited(n, vector< char >(m, '\0'));

    ll start_i, start_j;
    for(ll i=0; i<n; i++){
        for(ll j=0; j<m; j++){
            if(v[i][j] == 'A') start_i = i, start_j = j;
        }
    }
    
    deque< tuple< ll, ll > > q;
    q.push_back({ start_i, start_j });
    visited[start_i][start_j] = '-';
    while(!q.empty()){
        auto [i, j] = q.front();
        q.pop_front();

        if(v[i][j] == 'B') {
            cout << "YES" << "\n";
            string ans;
            while(visited[i][j] != '-'){
                ans.push_back(visited[i][j]);

                if(visited[i][j] == 'L') j++;
                else if(visited[i][j] == 'R') j--;
                else if(visited[i][j] == 'U') i++;
                else if(visited[i][j] == 'D') i--;
            }
            cout << ans.size() << "\n";
            for(auto c=ans.rbegin(); c!=ans.rend(); c++) cout << (*c);
            cout << "\n";
            return 0;
        }

        
        if(j+1 < m and v[i][j+1] != '#' and !visited[i][j+1]) {
            q.push_back({i, j+1});
            visited[i][j+1] = 'R';
        }
        if(j-1 >= 0 and v[i][j-1] != '#' and !visited[i][j-1])  {
            q.push_back({i, j-1});
            visited[i][j-1] = 'L';
        }
        if(i+1 < n and v[i+1][j] != '#' and !visited[i+1][j]) {
            q.push_back({i+1, j});
            visited[i+1][j] = 'D';
        }
        if(i-1 >= 0 and v[i-1][j] != '#' and !visited[i-1][j]) {
            q.push_back({i-1, j});
            visited[i-1][j] = 'U';
        }
    }

    cout << "NO" << "\n";
    return 0;
}