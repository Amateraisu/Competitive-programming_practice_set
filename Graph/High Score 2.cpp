#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int maxN = 2500 + 1;
constexpr int maxM = 5000 + 1;
constexpr ll INF = 0x3f3f3f3f3f3f3f;
ll dp[maxN];
struct edge {
    int a, b;
    ll c;
};

edge edges[maxM];

int n, m;
int a, b, c;
int main() {
    scanf("%d %d", &n, &m);
    memset(dp, dp + maxN, INF);
    for (int i = 0; i < m ; i++) {
        scanf("%d %d %d", &a, &b, &c);
    }


}