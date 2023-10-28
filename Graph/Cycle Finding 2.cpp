#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int maxN = 2501;
constexpr int maxM = 5000 + 1;
int a, b;
ll dis[maxN];
int p[maxN];
int n, m;
ll c;

struct edge {
    int a;
    int b;
    ll c;
};

edge edges[maxM];
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m ;i++) {
        scanf("%d %d %lld", &a, &b, &c);
        edges[i] = {a, b, c};
    }
    int ptr = -1;
    int improvement = 1;
    for (int i = 0 ; i < n && (improvement != -1); i++) {
        improvement = -1;
        ptr = -1;
        for (int j = 1; j <= m; j++) {
            edge e = edges[j];
            int u = e.a;
            int v = e.b;
            ll cost = e.c;
            if (dis[v] > dis[u] + cost) {
                improvement = 1;
                dis[v] = dis[u] + cost;
                p[v] = u;
                ptr = v;
            }
        }
    }
    if (ptr == -1) {
        printf("NO\n");
        return 0;
    }
    for (int i = 0; i < n; i++) {
        ptr = p[ptr];
    }
    vector<int>res;
    for (int i = ptr; ;i = p[i]) {
        res.push_back(i);
        if (i == ptr && static_cast<int>(res.size()) > 1) {
            break;
        }
    }
    reverse(res.begin(), res.end());
    cout << "YES\n";
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << '\n';
    }






    return 0;
}