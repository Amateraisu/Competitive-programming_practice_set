#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll t;
ll n, k;

void test() {
    cin >> n >> k;
    vector<ll>nums(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    if (k >= 3) {
        cout << '0\n';
        return;
    }
    if (k == 0) {
        cout << *min_element(nums.begin(), nums.end());
    }
    sort(nums.begin(), nums.end());
    if (k == 1) {

        ll res = nums[0];
        for (int i = 1; i < n; ++i) {
            res = min(res, nums[i] - nums[i - 1]);
        }
        cout << res << '\n';
        return;
    }
    // if k == 2
    ll res = nums[0];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            ll diff = nums[i] - nums[j];
            int index = lower_bound(nums.begin(), nums.end(), diff) - nums.begin();
            if (index < n) {
                res = min(res, nums[index] - diff);
            }
            if (index > 0) res = min(res, diff - nums[index - 1]);
        }
    }
    cout << res << '\n';
}



int main() {

    cin >> t;
    while (t--) test();
}
