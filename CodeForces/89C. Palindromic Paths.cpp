#include <bits/stdc++.h>
using namespace std;

void test() {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > a(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    vector<vector<int> > cnt(n + m - 1, vector<int>(2));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cnt[i + j][a[i][j]]++;
    long long res = 0;
    for (int i = 0; i < (n + m - 1)/2; ++i) {
        res += min(cnt[i][0] + cnt[n + m - 2 - i][0], cnt[i][1] + cnt[n + m - 2 - i][1]);
    }
    std::cout << res << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) test();
}