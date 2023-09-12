#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <queue>
using ll = long long;
using namespace std;


ll n = 2e5;
ll m,a,b;
vector<int>visited(n + 1, -1);
vector<vector<int>>g(n);
bool impossible = false;

void paint(int cur, int p) {
    int newCol = 0;
    if (visited[cur] == 1) newCol = 0;
    if (visited[cur] == 0) newCol = 1;
    for (auto x : g[cur]) {
        if (x != p) {
            if (visited[x] == -1) {
                visited[x] = newCol;
                paint(x, cur);
            } else {
                if (visited[x] == visited[cur]) impossible = true;
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m ; i++) {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        if (visited[i] == -1) {
            visited[i] = 1;
            paint(i, 0);
        }
    }
    if (impossible) {
        cout << "IMPOSSIBLE" << '\n';
        return 0;
    }
    for (int i = 1 ; i <= n; i++) {
        cout << (visited[i] ? 1 : 2) << ' ';
    }

    return 0;
}