#include <bits/stdc++.h>

using namespace std;

int arr[51][51];

bool can(int row , int col, vector<string>& mat) {
    vector<pair<int, int>>directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    queue<pair<int ,int>>q;
    char c = mat[row][col];

    q.push(make_pair(row, col));
    arr[row][col] = 1;
    while (!q.empty()) {
        auto p = q.front();q.pop();
        for (auto& [a, b]:directions) {
            int x1 = p.first + a;
            int y1 = p.second + b;
            if (x1 >= 0 && x1 < mat.size() && y1 >= 0 && y1 < mat[0].size() && mat[x1][y1] == c) {
                if (arr[p.first][p.second] == 1) return true;
                arr[x1][y1] = 1;
                q.push(make_pair(x1, y1));
            }
        }
    }
    return false;
}

int main() {
    int m, n;
    cin >> m >> n;
    vector<string>mat(m, "");
    for (int i = 0; i < 51; ++i) {
        for (int j = 0; j < 51; ++j) arr[i][j] = 0;
    }
    string s;
    for (int i = 0; i < m; ++i) {
        cin >> s;
        mat[i] = s;
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (arr[i][j] != 0) continue;
            if (can(i, j, mat)) {
                std::cout << "Yes\n";
                return 0;
            }
        }
    }
    std::cout << "NO\n";

    return 0;
}