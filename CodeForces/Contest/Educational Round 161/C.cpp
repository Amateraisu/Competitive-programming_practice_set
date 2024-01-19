#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll t;


void test() {
    int n, m;
    int a, b;
    cin >> n;
    vector<int>nums(n, 0);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    vector<ll>left(n, 0);
    vector<ll>right(n, 0);
    cin >> m;
    if (n == 1){
        for (int i = 0; i < m; ++i) {
            cin >> a >> b;
            cout << 0 << '\n';
        }
        return;
    }

    left[1] = 1;
    right[n - 2] = 1;
    for (int i = 1; i < n - 1; ++i) {
        ll r = nums[i + 1] - nums[i];
        ll l = nums[i] - nums[i - 1];
        if (r < l) {
            left[i + 1] = left[i] + 1;
        } else {
            left[i + 1] = left[i] + r;
        }
    }

    for (int i = n - 2; i >= 1; --i) {
        ll l = abs(nums[i - 1] - nums[i]);
        ll r = abs(nums[i] - nums[i + 1]);
        if (l < r) {
            right[i - 1] = right[i] + 1;
        } else {
            right[i - 1] = right[i] + l;
        }
    }
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        if (a == b) {
            cout << 0 << '\n';
        } else if (a < b) {
            cout << left[b - 1] - left[a - 1] << '\n';
        } else {
            cout << right[b - 1] - right[a - 1] << '\n';
        }
    }

}


int main() {
    cin >> t;
    while (t--) test();
}
