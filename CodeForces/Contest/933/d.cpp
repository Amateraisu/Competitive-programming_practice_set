#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF = 0x3f3f3f3f3f3f3f3f;

void test() {
    ll n, m, s;
    cin >> n >> m >> s;
    --s;
    vector<ll>dpo(n, 0);
    vector<ll>dp(n, 0);
    dpo[s] = 1;
    for (int i = 0; i < m; ++i) {
        ll a;
        char b;
        cin >> a >> b;
        for (int j = 0; j < n; ++j) {
            if (dpo[j] == 1) {
                ll clockwise = (j + a) % n;
                ll antiClockwise = (j - a + n) % n;
                if (b == '?') {
                    dp[clockwise] = 1;
                    dp[antiClockwise] = 1;
                } else if (b == '0') {
                    dp[clockwise] = 1;

                } else if (b == '1') {
                    dp[antiClockwise] = 1;
                }
            }
        }
        dpo = dp;
        fill(dp.begin(), dp.end(), 0);
    }
    ll sz = 0;
    for (int i = 0; i < n; ++i) {
        if (dpo[i] == 1) ++sz;
    }
    cout << sz << '\n';
    for (int i = 0; i < n; ++i) {
        if (dpo[i] == 1) cout << i + 1 << ' ';
    }
    cout << '\n';



}

int main() {
    int n;
    cin >> n;
    while (n--) test();

    return 0;
}
