#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// To execute C++, please define "int main()"
ll dp[100][100][2];

void reset() {
    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 100; ++j) {
            dp[i][j][0] = -1;
            dp[i][j][1] = -1;
        }
    }
}

ll calculate(ll x, ll y, ll z, ll num, ll k, ll d) {
    if (dp[x][y][z] != -1) return dp[x][y][z];
    if (x == std::to_string(num).size()) {
        return y == k ? 1 : 0;
    }
    int limit = 9;
    if (!z) limit = std::to_string(num)[x] - '0';
    dp[x][y][z] = 0;
    for (int i = 0; i <= limit; ++i) {
        if (z) {
            // if I am at the limit,
            dp[x][y][z] += calculate(x + 1, y + (to_string(num)[x] == d), 1 ,num, k, d);

        } else {
            // if I am not at the limit
            dp[x][y][z] += calculate(x + 1, y + (to_string(num)[x] == d), i < to_string(num)[x], num, k ,d);
        }
    }

    return dp[x][y][z];
}

ll get(ll upper, ll k, ll d) {
    reset();
    ll res = calculate(0, 0, 1, upper, k, d);
    return res;
}



int main() {
    ll a, b, k , d;
    cin >> a >> b >> k >> d;
    cout << get(b, k, d) - get(a - 1, k ,d) << '\n';
    return 0;
}