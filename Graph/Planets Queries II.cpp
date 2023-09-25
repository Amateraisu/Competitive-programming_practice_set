#include <bits/stdc++.h>
using ll = long long;
constexpr int maxN = 2e5 + 1;
using namespace std;
int q;
constexpr int bits = 31;
int dp[maxN][bits];
int n, a, b;
int lvl[maxN];
int g[maxN];




void dfs(int cur = 1, int p = -1, int height = 0) {
    if (lvl[cur] != 0) return;
    lvl[cur] = height;
    dfs(g[cur], cur, height + 1);
}




int main() {
    scanf("%d %d", &n , &q);
    for (int i = 1 ; i<= n; i++) {
        cin >> g[i];
        lvl[i] = 0;
    }
    dfs();



    return 0;
}