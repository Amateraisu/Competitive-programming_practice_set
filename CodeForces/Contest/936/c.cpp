#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct temp {
    int size = 0;
    int res = 0;
};

temp dfs(int u , int p , int req, map<int, vector<int>>& g) {
    int cur = 1;
    int cnt = 0;
    for (int v : g[u]) {
        if (v == p) continue;
        temp t =  dfs(v, u, req, g);
        cur += t.size;
        cnt += t.res;

    }
    if (cur >= req) {
        ++cnt;
        cur = 0;
    }
    return {cur, cnt};
}

void test() {
    int n, k;
    cin >> n >> k;
    map<int, vector<int>>g;
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int r = n;
    int l = 1;


    auto ok = [&](ll size)->ll {
        temp cnt = dfs(1, -1, size, g);
        return cnt.res;
    };
    int res = -1;
    while (l <= r) {
        int m = l + (r - l)/2;
        if (ok(m) > k) {
            res = m;
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    cout << res << '\n';
}

int main() {
    int n;
    cin >> n;
    while (n--) test();
}