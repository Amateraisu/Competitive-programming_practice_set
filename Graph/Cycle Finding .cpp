#include <bits/stdc++.h>
using ll = long long;
const int maxN = 2500 + 1;
const int maxM = 5000 + 1;
const ll INF = 0x3f3f3f3f3f3f3f3f;
using namespace std;
struct Edge {
    int a, b;
    ll c;
};

Edge edges[maxM];
int N, M, ptr, p[maxN];
ll dp[maxN];
int a, b;
ll c;

int main() {
    cin >> N >> M;
    for (int i = 1 ; i <= N; i++) dp[i] = INF;
    for (int i = 1; i <= M; i++) {
        cin >> a >> b >> c;
        edges[i] = {a , b, c};
    }
    ptr = -1;
    for (int i = 1; i <= N && ptr ; i++) {
        ptr = 0;
        for (auto e : edges) {
            int fro = e.a;
            int to = e.b;
            ll c = e.c;
            if (dp[to] > dp[fro] + c) {
                dp[to] = dp[fro] + c;
                p[to] = fro;
                ptr = to;
            }
        }
    }
    if (!ptr) {
        cout << "NO\n";
        return 0;
    }
    for (int i = 0; i < N; i++) {
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