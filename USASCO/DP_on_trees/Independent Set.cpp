#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll MOD = 1e9 + 7;
const int maxN = 1e5 + 1;
vector<int> G[maxN];
int dp1[maxN], dp2[maxN];
void dfs(int u, int p) {
    int s1 = 1;
    int s2 = 1;

    for (int v : G[u]) {
        if (v == p) continue;
        dfs(v, u);
        s2 = (1LL * s2 * (dp2[v] + dp1[v])) % MOD;
    }
    for (int v : G[u]) {
        if (v == p) continue;
        s1 = (1LL * s1 * dp2[v]) % MOD;
    }


    dp1[u] = s1;
    dp2[u] = s2;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(1, -1);
    cout << (dp1[1] + dp2[1]) % MOD << '\n';
}



