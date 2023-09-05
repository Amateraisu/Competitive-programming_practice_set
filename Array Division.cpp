#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
using ll = long long;
int n , k;

int main() {
    cin >> n >> k;
    vector<ll>nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    ll res = 0;
    ll l = 0;
    ll r = 0;
    for (int i = 0 ; i < n; i++) {
        r += nums[i];
        l = max(l, (ll)nums[i]);
    }

    auto valid = [&](ll middle) {
        int res = 1;
        ll cur = 0;
        for (int i = 0; i < n; i++) {
            cur += nums[i];
            if (nums[i] > middle) return false;
            if (cur > middle) cur = nums[i], res++;
        }
        return res <= k;
    };
    while (l <= r) {
        ll m = l + (r - l)/2;
        if (valid(m)) {
            res = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    cout << res << '\n';


    return 0;
}
