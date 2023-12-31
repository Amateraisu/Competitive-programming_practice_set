#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll t;

ll get(ll total, int odd, int even) {

    if (odd + even == 1) return total;
    if (odd == 1 && even == 1) return total - 1;
    ll deduct = 0;
    // for the final operation, will he be forced to deduct?
    // so I have some odd numbers.
    // he will always choose to decrement the odds. so O has no chance
    if (odd % 3 == 1) {
        ++deduct;
    }
    ll can = odd / 3;
    deduct += can;
    // cout << canTake << ' ' << can << ' ' << deduct << '\n';
    // cout << "FINAL " << total << ' ' << deduct << '\n';
    return total - deduct;

}
void test() {
    int n;
    cin >> n;
    vector<int>nums(n, 0);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    vector<ll>res(n, -1);
    ll cur = 0;
    int odd = 0;
    int even = 0;
    for (int i = 0; i < n; ++i) {
        if (nums[i] % 2 == 0) {
            ++even;
        } else {
            ++odd;
        }
        cur += nums[i];
        ll r = get(cur, odd, even);
        res[i] = r;
        ;    }
    for (int i = 0; i < n; ++i) {
        cout << res[i] << ' ';
    }
    cout << '\n';
}

int main() {
    cin >> t;
    while (t--) test();
}
