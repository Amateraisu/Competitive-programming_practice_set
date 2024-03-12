#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF = 0x3f3f3f3f3f3f3f3f;



ll get(vector<int>& A, int d) {
    vector<ll>dp(A.size(), 0);
    multiset<ll>s;
    int n = A.size();
    dp[0] = 1;
    s.insert(1);
    for (int i = 1; i < n; ++i) {
        auto it = s.begin();
        dp[i] = *it + A[i] + 1LL;
        if (i - d - 1 >= 0) s.erase(s.find(dp[i - d - 1]));
        s.insert(dp[i]);
        // cout << "POSITION " << i << " " << dp[i] << '\n';

    }
    // cout << "HERE\n";
    // cout << "FINAL COST " << dp[A.size() - 1] << '\n';
    return dp[A.size() - 1];

}




void test() {
    int n, m, k, d;
    cin >> n >> m >> k >> d;
    vector<vector<int>>A(n, vector<int>(m, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> A[i][j];
        }
    }
    vector<ll>costs;
    for (auto& a : A) {
        ll cost = get(a, d);
        costs.push_back(cost);
    }
    ll res = INF;

    // get the minimum sliding window
    int l = 0;
    ll cur = 0;
    for (int r = 0; r < n; ++r) {
        cur += costs[r];
        if (r - l + 1 > k) {
            cur -= costs[l];
            ++l;
        }
        if (r - l + 1 == k) {
            res = min(res, cur);
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
