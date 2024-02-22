#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void test() {
    int n;
    cin >> n;
    map<int, vector<int>>mp;
    vector<int>nums(n, 0);
    vector<int>ret(n, 0);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    for (int i = 0; i < n; ++i) {
        mp[nums[i]].push_back(i);
    }
    ll cnt = 2;

    for (auto& [a, b] : mp) {
        // cout << a << ' ' << b.size() << '\n';
        if (b.size() > 1) --cnt;

    }
    // cout << cnt << '\n';
    if (cnt > 0) {
        cout << -1 << '\n';
        return;
    }
    bool flag = true;
    for (auto& [a, b] : mp) {
        nums[b[0]] = 1;

        for (int i = 1; i < b.size(); ++i) {
            if (flag) {
                nums[b[i]] = 2;
            } else {
                nums[b[i]] = 3;
            }
        }
        if (b.size() > 1) flag = !flag;

    }
    for (int x : nums) {
        cout << x << ' ';
    }
    cout << '\n';
}




int main() {
    int n;
    cin >> n;
    while (n--) test();
}