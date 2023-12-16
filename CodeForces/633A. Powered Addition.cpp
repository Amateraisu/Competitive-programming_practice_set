#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll t, n;
void test() {
    cin >> n;
    vector<ll>nums(n, 0);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    ll cur = 0;

    ll res=  0;
    for (int i = 1; i < n; ++i) {
        if (nums[i] < nums[i - 1]) {
            res = max(res, nums[i - 1] - nums[i]);
            nums[i] = nums[i - 1];
        }
    }

    cout << ceil(log2(res + 1)) << '\n';

}


int main() {
    cin >> t;
    while (t--) test();
}
