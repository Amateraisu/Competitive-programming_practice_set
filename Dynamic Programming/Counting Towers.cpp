#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
using ll = long long;
using namespace std;

ll n, t, q;

int main() {
    cin >> t;

    // construct the tower
    n = 1e6;
    vector<ll>sep(n, 0);
    vector<ll>tgt(n, 0);
    sep[0] = 1;
    tgt[0] = 1;
    int MOD = 1e9 + 7;
    for (int i = 1; i <= n; i++) {
        sep[i] = (4 * sep[i - 1]) % MOD  + tgt[i - 1] % MOD;
        sep[i] %= MOD;
        tgt[i] = (tgt[i - 1] * 2) % MOD + sep[i - 1] % MOD;
        tgt[i] %= MOD;
    }
    for (int i = 0; i < t ;i++) {
        cin >> q;
        cout << (sep[q - 1] + tgt[q - 1]) % MOD << '\n';
    }

    return 0;
}
