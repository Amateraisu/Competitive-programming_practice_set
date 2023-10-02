#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int n,m, a, b;
constexpr int maxN = 2e5 + 1;
vector<int> g[maxN];
int visited[maxN];
using edge = tuple<int, int>;
int p[maxN];


void ret() {


}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        p[i] = i;
    }
    queue<edge>q;
    q.push({1, 1});
    p[1] = 1;
    visited[1] = 1;
    while (!q.empty()) {
        edge e = q.front(); q.pop();
        int u = get<0>(e);
        int c = get<1>(e);
        if (u == n) {
            printf("%d\n", c);
            break;

        }
        for (int v : g[u]) {
            if (!visited[v]) {
                p[v] = u;
                visited[v] = 1;
                q.push({v, c + 1});
            }
        }
    }
    if (visited[n] == 0) {
        printf("IMPOSSIBLE");
        return 0;
    }
    int ptr = n;
    vector<int>res;
    while (ptr != p[ptr]) {
        res.push_back(ptr);
        ptr = p[ptr];
    }
    reverse(res.begin(), res.end());
    printf("1 ");
    for (int i = 0; i < res.size(); i++) printf("%d ", res[i]);


    return 0;
}