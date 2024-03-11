// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int>IN(n + 1, 0);
    map<int, vector<int>>g;
    for (int i = 0; i < m ;++i) {
        // here is the prerequisites
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        ++IN[b];
    }
    vector<int>res;
    queue<int>q;
    for (int i = 1; i <= n; ++i) {
        if (IN[i] == 0) q.push(i);
    }
    while (!q.empty()) {
        auto f = q.front(); q.pop();
        res.push_back(f);
        for (int v: g[f]) {
            --IN[v];
            if (IN[v] == 0) {
                q.push(v);
            }
        }
    }
    if (res.size() != n) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    for (int x : res) {
        cout << x << ' ';
    }

    cout << '\n';
}