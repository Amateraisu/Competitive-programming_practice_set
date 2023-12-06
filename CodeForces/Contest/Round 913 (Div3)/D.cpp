#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using p = pair<ll,ll>;

ll t, n;
void test() {
    cin >> n;
    ll l, r;
    vector<p>s;
    for (int i = 0; i < n; ++i) {
        cin >> l >> r;
        s.push_back({l, r});
    }
    r = 1e9;
    l = 0;
    ll res = r;
    auto ok = [&](ll m) {
        ll left = 0, right = 0;
        for (auto it : s) {
            left = max(left - m, it.first);
            right = min(right + m, it.second);
            if (left > right) return false;
        }
        return true;
    };
    while (l <= r) {
        ll m = l + (r- l)/2;
        if (ok(m)) {
            res = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    cout << res << '\n';



}
int main() {
    cin >> t;
    while (t--) test();
}
