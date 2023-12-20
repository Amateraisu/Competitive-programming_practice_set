#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int t;

void test() {
    int n;
    cin >> n;
    vector<int>nums(n, 0);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    vector<int>pref(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        pref[i] = pref[i - 1] + nums[i - 1];
    }
    set<int>h;
    for (int i = 0; i <=n; ++i) {
        for (int j = i + 2; j <=n; ++j) {
            int diff = pref[j] - pref[i];
            h.insert(diff);
        }
    }
    int res = 0;
    for (int i = 0; i < n; ++i) if (h.find(nums[i]) != h.end()) {
        ++res;
    }
    cout << res << '\n';
}

int main() {
    cin >> t;
    while (t--) test();
}
