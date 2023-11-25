#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n;
ll x;
int main() {
    scanf("%lld %lld", &n, &x);
    vector<ll>nums(n, 0);
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &nums[i]);
    }
    auto c = [&](int l, int r) ->vector<ll> {
        int length = r - l + 1;
        vector<ll>res;
        for (int i = 0; i < (1 <<  length); ++i) {
            ll sum = 0;
            for (int j = 0; j < length; ++j) {
                if (i & (1 << j)) {
                    sum += nums[l + j];
                }
            }
            res.push_back(sum);
        }

        return res;
    };
    vector<ll> l1 = c(0, n/2 - 1);
    vector<ll> l2 = c(n/2, n - 1);
    sort(l1.begin(), l1.end());
    sort(l2.begin(), l2.end());
    ll res = 0;
    for (ll i: l1) {
        auto low = lower_bound(l2.begin(), l2.end(), x - i);
        auto high = upper_bound(l2.begin(), l2.end(), x - i);
        int start = low - l2.begin();
        int end = high - l2.begin();
        res += end - start;
    }
    cout << res << '\n';
    return 0;
}
