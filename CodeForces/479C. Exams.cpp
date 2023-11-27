#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using edge = tuple<int, int>;
ll a, b;
ll n;
int main() {
    cin >> n;
    vector<edge>dp;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        dp.push_back({a, b});
    }
    sort(dp.begin(), dp.end());
    int res = -1;
    for (int i = 1; i < n; ++i) {
        auto e = dp[i];
        int actual = get<0>(e);
        int special = get<1>(e);
        if (res <= special) {
            res = special;
        } else {
            res = actual;
        }
    }
    cout << res << '\n';
    

    return 0;
}
