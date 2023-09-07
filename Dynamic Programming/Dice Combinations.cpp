#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
using ll = long long;
using namespace std;

ll n;
int main() {
    cin >> n;
    int MOD = 1e9 + 7;
    vector<int>cnt(n + 1, 0);
    cnt[0] = 1;
    for (int i = 0; i <= n; i++) {
        for (int j = 1; j <= 6; j++) {
            if (i - j < 0) break;
            cnt[i] += cnt[i - j] % MOD;
            cnt[i] %= MOD;
        }
    }
    cout << cnt[n] << '\n';
    return 0;
}