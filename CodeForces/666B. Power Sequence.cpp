#include <bits/stdc++.h>
using ll = long long;
using namespace std;

ll f(ll m, vector<int>& nums) {
    ll ret = 0;
    for (int i = 0; i < nums.size(); ++i) {

    }

    return ret;
}

void test() {
    int n;
    cui
    vector<int>nums(n, 0);
    ll l = 0;
    ll r = 0;
    for (int i = 0; i < n; ++i) cin >> nums[i], r = max(r, 1LL*nums[i]);
    ll cost = 0x3f3f3f3f3f3f3f3f;
    std::sort(nums.begin(), nums.end());
    while (l <= r) {
        ll m = l + (r - l)/2;
        ll nc = f(m, nums);
        // try using this c**i
        if (nc  < cost) {
            // if the cost is lower, try using
            cost = nc;
            r = m - 1;

        } else {
            l = m + 1;

        }
    }

}


int main() {
    int n;
    cin >> n;
    while (n--) test();
}
