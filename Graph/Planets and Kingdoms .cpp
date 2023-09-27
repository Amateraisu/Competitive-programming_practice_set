
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr int maxN = 1e5 + 1;
constexpr int maxM = 2e5 + 1;
int n, m, a, b;
vector<int> g1[maxN], g2[maxN];
int v1[maxN], v2[maxN];
stack<int>s;
vector<vector<int>>r(maxN);
int c = 1;
int comp[maxN];
void dfs1(int u) {
    v1[u] = 1;
    for (int v: g1[u]) {
        if (v1[v] == 0) {
            dfs1(v);
        }
    }
    s.push(u);
}

void dfs2(int u) {
    comp[u] = c;
    r[c].push_back(u);
    v2[u] = 1;
    for (int v: g2[u]) {
        if (!v2[v]) {
            dfs2(v);
        }
    }


}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0 ; i < m; i++) {
        scanf("%d %d", &a, &b);
        g1[a].push_back(b);
        g2[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        v1[i] = 0;
        v2[i] = 0;
    }

    for (int i = 1; i <= n; i++) {
        if (v1[i] == 0) {
            dfs1(i);
        }
    }
    while (!s.empty()) {
        int u = s.top();
        s.pop();
        if (!v2[u]) {
            dfs2(u);
            c++;
        }
    }
    printf("%d\n", c - 1);
    for (int i = 1 ; i <= n; i++) {
        printf("%d ", comp[i]);
    }
    return 0;

}
