#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll t;
constexpr ll INF = 0x3f3f3f3f3f3f3f3f;

void test() {
    int n;
    cin >> n;
    vector<int>nums(n, 0);
    for (int i = 0 ; i < n; ++i) cin >> nums[i];
    ll maxi = -INF;
    ll mini = INF;
    for (int i = 0; i < n; ++i) {
        if (nums[i] == -1) {
            if (i - 1 >= 0) {
                maxi = max(maxi, 1LL * nums[i - 1]);
                mini = min(mini, 1LL * nums[i - 1]);
            }
            if (i + 1 < n) {
                maxi = max(maxi, 1LL * nums[i - 1]);
                mini = min(mini, 1LL * nums[i - 1]);
            }
        }
    }
    ll diff = maxi - mini;
    std::cout << diff/2 << ' ' << mini + diff/2;


}
int main() {
    cin >> t;
    while (t--) test();
}