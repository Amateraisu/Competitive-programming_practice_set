#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void test() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int& num : nums) {
        cin >> num;
    }
    sort(nums.begin(), nums.end());
    set<int> s(nums.begin(), nums.end());
    vector<int>nums2(s.begin(), s.end());
    int l = 0;
    int res = 1;
    for (int r = 0; r < n; ++r) {
        while (nums2[l] + n < nums2[r]) {
            ++l;
        }
        res = max(res, r - l + 1);
    }
    cout << res << '\n';
}

int main() {
    ll t;
    cin >> t;
    while (t--) test();
}