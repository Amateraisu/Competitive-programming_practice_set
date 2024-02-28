#include <bits/stdc++.h>
using namespace std;
using ll = long long;



void test() {
    int n;
    cin >> n;
    vector<int>nums(n, 0);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    vector<int>d(n, 0);
    for (int i = 0; i < n - 1; ++i) d[i] = nums[i + 1] - nums[i];
    for (int i = 0; i < n; ++i) {
        if (d[i] < 0 && ((i & (i - 1))) == 1) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) test();
}
