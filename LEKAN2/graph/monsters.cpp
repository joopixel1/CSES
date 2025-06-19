#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;
using ll = long long;

string trace(ll i, ll j, vector<string>& graph){
    string ans;
    vector< vector<bool> > visited(graph.size(), vector<bool>(graph[0].size(), false));
    deque<tuple<int, int, string>> q;
    visited[i][j] = true;
    q.push_back( make_tuple(i, j, "") );
    while(!q.empty()){
        auto [x, y, path] = q.front();
        q.pop_front();

        if(graph[x][y] == 'B') {
            ans = path;
            break;
        }

        if(x-1>=0 and graph[x-1][y]!='#' and !visited[x-1][y]){
            visited[x-1][y] = true;
            q.push_back( make_tuple(x-1, y, path+"U") );
        }
        if(x+1<graph.size() and graph[x+1][y]!='#' and !visited[x+1][y]){
            visited[x+1][y] = true;
            q.push_back( make_tuple(x+1, y, path+"D") );
        }
        if(y-1>=0 and graph[x][y-1]!='#' and !visited[x][y-1]) {
            visited[x][y-1] = true;
            q.push_back( make_tuple(x, y-1, path+"L") );
        }
        if(y+1<graph[0].size() and graph[x][y+1]!='#' and !visited[x][y+1]) {
            visited[x][y+1] = true;
            q.push_back( make_tuple(x, y+1, path+"R") );
        }
    }

    return ans;
}

// string trace(ll i, ll j, vector<string>& graph){
//     vector< vector<char> > path(graph.size(), vector<char>(graph[0].size(), 0));
//     vector< vector<bool> > visited(graph.size(), vector<bool>(graph[0].size(), false));
//     deque< pair<int, int> > q;
//     visited[i][j] = true;
//     q.push_back( make_pair(i, j) );
//     while(!q.empty()){
//         auto x = q.front().first, y = q.front().second;
//         q.pop_front();

//         if(graph[x][y] == 'B') {
//             string ans;
//             int a = x, b = y;
//             while(graph[a][b] != 'A'){
//                 char c = path[a][b];
//                 ans+=c;

//                 if(c == 'L') b++;
//                 if(c == 'R') b--;
//                 if(c == 'U') a++;
//                 if(c == 'D') a--;
//             }
//             reverse(ans.begin(), ans.end());
//             return ans;
//         }

//         if(x-1>=0 and graph[x-1][y]!='#' and !visited[x-1][y]){
//             visited[x-1][y] = true;
//             path[x-1][y] = 'U';
//             q.push_back( make_pair(x-1, y) );
//         }
//         if(x+1<graph.size() and graph[x+1][y]!='#' and !visited[x+1][y]){
//             visited[x+1][y] = true;
//             path[x+1][y] = 'D';
//             q.push_back( make_pair(x+1, y) );
//         }
//         if(y-1>=0 and graph[x][y-1]!='#' and !visited[x][y-1]) {
//             visited[x][y-1] = true;
//             path[x][y-1] = 'L';
//             q.push_back( make_pair(x, y-1) );
//         }
//         if(y+1<graph[0].size() and graph[x][y+1]!='#' and !visited[x][y+1]) {
//             visited[x][y+1] = true;
//             path[x][y+1] = 'R';
//             q.push_back( make_pair(x, y+1) );
//         }
//     }

//     return "";
// }

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // cout << "Starting..." << "\n";

    ll n, m;
    cin >> n >> m;
    string s;
    vector<string> graph;
    for (ll i=0; i<n; i++) {
        cin >> s;
        graph.push_back(s);
    }

    pair<ll, ll> A;
    vector< pair<ll, ll> > M;
    for(ll i=0; i<n; i++){
        for(ll j=0; j<m; j++){
            if(graph[i][j] == 'A') A = make_pair(i, j);
            if(graph[i][j] == 'A') M.push_back( make_pair(i, j) );
        }
    }

    auto ans = dfs(A, B, graph);
    if(ans.size() == 0) cout << "NO" << "\n";
    else {
        cout << "YES" << "\n";
        cout << ans.size() << "\n";
        cout << ans << "\n";
    }

    return (0);
}