#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int t;

void test() {
    int n;
    cin >> n;
    vector<int>nums(n, 0);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    map<int, int>mp;
    map<int, int>mp2;
    for (int x : nums) ++mp[x];
    for (auto& [a, b]: mp) ++mp2[b];
    ll left = 0;
    ll right = n;
    ll c = mp.size();
    ll res = 0x3f3f3f3f3f3f3f3f;
    for (auto& [a, b]: mp2) {
        res = min(res, left + right - c * a);
        left += a * b;
        right -= a * b;
        c -= b;
    }
    cout << res << '\n';
}


int main() {
    cin >> t;
    while (t--) test();
}
