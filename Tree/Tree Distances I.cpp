#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
using ll = long long;
using namespace std;
int a, b;
int n = 2e5 + 1;
vector<int>res(n, 0);
vector<vector<int>>g(n);




int bfs(int s) {
    int top;
    queue<int>q;
    vector<int> d(n + 1, -1);
    d[s] = 0;
    res[s] = max(res[s], d[s]);
    q.push(s);
    while (!q.empty()) {
        top = q.front();
        q.pop();
        for (auto v : g[top]) {
            if (d[v] == -1) {
                q.push(v);
                d[v] = d[top] + 1;
                res[v] = max(res[v], d[v]);
            }
        }
    }
    return top;

}

int main() {
    cin >> n;
    // first dfs
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int n1 = bfs(1);
    int n2 = bfs(n1);
    bfs(n2);
    for (int i = 1; i<= n; i++) {

        cout << res[i] << ' ';
    }

    return 0;
}
