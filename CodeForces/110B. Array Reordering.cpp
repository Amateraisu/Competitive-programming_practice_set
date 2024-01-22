#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll t;


void test() {
    int n;
    cin >> n;
    vector<int>nums(n, 0);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    auto c = [](int a, int b) {
        if (a % 2 == 0) return a < b;
        return a > b;
    };
    ll res = 0;
    sort(nums.begin(), nums.end(), c);
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (gcd(nums[i], nums[j]*2) > 1) {cout << "VALID " << i << ' ' << j <<'\n'; ++res;}
        }
    }
    cout << res << '\n';
}

int main() {
    cin >> t;
    while (t--) test();
}
