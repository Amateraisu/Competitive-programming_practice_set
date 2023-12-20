#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n;
constexpr int MOD = 1e9 + 7;
// map<int, vector<int>> mp = {
//         {4, {2, 3, 1}},
//         {2, {1, 3, 4}},
//         {3, {2, 4, 1}},
//         {1, {2, 4, 3}}
// };


int main() {
    cin >> n;
    ll p1 = 0, p2 = 0, p3 = 0, p4 = 1;
    for (int i = 1; i <= n; ++i) {
        ll tot = p1 + p2 + p3 + p4;
        tot %= MOD;
        p1 = ((tot - p1) % MOD + MOD) % MOD;
        p2 = ((tot - p2) % MOD + MOD) % MOD;
        p3 = ((tot - p3) % MOD + MOD) % MOD;
        p4 = ((tot - p4) % MOD + MOD) % MOD;
    }

    cout << p4 << '\n';

}
