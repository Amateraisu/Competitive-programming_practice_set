#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll t;


void test() {
    int n;
    cin >> n;
    vector<int>nums(n, 0);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    vector<int>score(n, 0);
    auto c = [](int a, int b) {
        return a > b;
    };
    sort(nums.begin(), nums.end(), c);
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (gcd(nums[i] , nums[j] * 2) > 1) {
                ++score[i];
            }
        }
    }
    auto d = [&](int a, int b) {
        return score[a] > score[b];
    };
    sort(nums.begin(), nums.end(), d);
    ll res = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (gcd(nums[i], nums[j] * 2) > 1) ++res;
        }
    }
    cout << res << '\n';
}

int main() {
    cin >> t;
    while (t--) test();
}
