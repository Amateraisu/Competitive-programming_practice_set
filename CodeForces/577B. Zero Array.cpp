#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int INF = 0x3f3f3f3f;

int main() {
    int n;
    cin >> n;
    vector<int>nums(n, 0);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    sort(nums.begin(), nums.end());
    ll maxi = nums[n - 1];
    ll tot = 0;
    for (int i = 0; i < n-  1; ++i) tot += nums[i];
    if (accumulate(nums.begin(), nums.end(), 0) % 2 == 0 && maxi <= tot) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}
