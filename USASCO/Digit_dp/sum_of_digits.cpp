#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll dp[100][180][2];


void reset() {
    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 180; ++j) {
            dp[i][j][0] = -1;
            dp[i][j][1] = -1;
        }
    }
}

ll calc(ll num, ll x, ll y, ll z) {
    if (dp[x][y][z] != -1) return dp[x][y][z];
    if (x == to_string(num).size()) return y;
    int limit = 9;
    dp[x][y][z] = 0;
    if (!z) limit = to_string(num)[x] - '0';
    for (int i = 0; i <=  limit; ++i) {
        if (z) {
            // can exceed limit
            dp[x][y][z] += calc(num, x + 1, y + i, 1);
        }
        else {
            dp[x][y][z] += calc(num, x + 1, y + i, i < limit);
        }

    }


    return dp[x][y][z];



}

ll get(ll upper) {
    reset();
    ll res = calc(upper,0, 0, 0);
    return res;
}

// To execute C++, please define "int main()"
int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        ll a, b;
        cin >> a >> b;
        cout << get(b) - get(a - 1) << '\n';

    }

    return 0;
}