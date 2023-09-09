#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
set<pair<int,int>>s;
int res = 0;
int m, n;
vector<int>xDir = {-1, 1, 0, 0};
vector<int>yDir = {0, 0, -1, 1};
vector<vector<string>>mp(m , vector<string>(n, ""));

void dfs(int row, int col) {
    if (s.find({row, col}) != s.end()) return;
    s.insert({row, col});
    for (int i = 0; i < 4; i++) {
        int nx = row + xDir[i], ny = col + yDir[i];
        if (nx >= 0 && nx < m && ny >= 0 && ny < n && mp[nx][ny] == ".") {
            dfs(nx, ny);
        }
    }
    return ;
}
int main() {
    cin >> m >> n;
    for (int i = 0 ; i < m ; i++) {
        for (int j = 0; j < n ; j++) {
            cin >> mp[i][j];
        }
    }
    for (int i = 0; i < m ; i++) {
        for (int j = 0; j < n; j++) {
            if (mp[i][j] == "." && s.find({i, j}) == s.end()) {
                res++;
                dfs(i, j);
            }
        }
    }
    cout << res << '\n';

    return 0;
}