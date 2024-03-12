// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
using ll = long long;


void test() {
    int n, m, k;
    cin >> n >> m >> k;
    ll res = 0;
    vector<int>A(n, 0);
    vector<int>B(m, 0);
    for (int i = 0; i < n; ++i) cin >> A[i];
    for (int i = 0; i < m; ++i) cin >> B[i];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (A[i] + B[j] <= k) ++res;
        }
    }
    cout << res << '\n';
}

int main() {
    int n;
    cin >> n;
    while (n--) test();

    return 0;
}
