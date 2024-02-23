#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll dp[200][2];


ll calc(ll num, ll x, ll z) {
    if (dp[x][z] != -1) return dp[x][z];
    if (x == to_string(num).size()) return 1;
    int limit = 9;
    if (!z) {
        limit = to_string(num)[x] - '0';
    }
    dp[x][z] = 0;
    ll ret = 0;
    for (int i = 0; i <= limit; ++i) {
        if (z) {
            ret = max(ret, calc(num, x + 1, 1) * i);
        } else {
            ret = max(ret, calc(num, x + 1, i < limit));
        }
    }
    dp[x][z] = ret;
    return dp[x][z];
}

void reset() {
    for (int i = 0; i < 200; ++i) {
        dp[i][0] = -1;
        dp[i][1] = -1;
    }
}

ll get(ll num) {
    reset();
    return calc(num,0,0);
}


int main() {
    ll a, b;
    cin >> a >> b;
    cout << get(b) - get(a - 1) << '\n';
}
