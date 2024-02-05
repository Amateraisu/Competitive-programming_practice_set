#include <bits/stdc++.h>
using namespace std;
using ll = long long;


struct p {
    ll num;
    bool can;
};
int main() {
    ll n, m;
    cin >> n >> m;
    vector<ll>nums(n, 0);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    ll l = 0, r = n;
    ll res = 0, resC = 0;
    auto ok = [&](ll count) -> p {
        ll cost = 0;
        bool can = false;
        vector<ll>t(n, 0);
        for (int i = 0; i < count; ++i) {
            t[i] = nums[i] + count * i;
        }
        sort(t.begin(), t.end());
        for (int i = 0; i < count; ++i) {
            cost += t[i];
        }
        if (cost > m) {
            return {0, false};
        }

        return {cost, can};
    };
    while (l <= r) {
        ll mid = l + (r - l)/2;
        p ret = ok(mid);
        bool can = ret.can;
        if (can) {
            res = mid;
            resC = ret.num;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    std::cout << res << ' ' << resC << '\n';
}