#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;
using ll = long long;
int n, a, b;

int main() {
    cin >> n >> a >> b;
    vector<ll> pref(n + 1, 0);
    vector<int> nums(n + 1, 0);
    for (int i = 1; i <= n ; i++) cin >> nums[i];
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + nums[i];
    }
    set<pair<ll, ll>>s;
    for (int i = a ; i <= b; i++) s.insert({pref[i], i});
    ll res = -1e18;
    for (int i = 1; i <= n - a + 1; i++) {
        res = max(res, s.rbegin()->first - pref[i - 1]);
        s.erase({pref[i + a - 1], i + a - 1});
        if (i + b <= n) s.insert({pref[i + b], i + b});

    }
    cout << res << '\n';

    return 0;
}
