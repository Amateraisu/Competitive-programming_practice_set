#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int t;
int n, k;

void test() {
    vector<int>nums(n, 0);
    unordered_set<int>s;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
        s.insert(nums[i]);
    }
    if (s.size() == 1) {
        cout << "YES\n";
        return;
    }
    bool p = true;
    for (int i = 1; i < n; ++i) {
        if (nums[i] - nums[i - 1] < 0) p = false;
    }
    if (p) {
        cout << "YES\n";
        return;
    }

    if (k > 1) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> n >> k;
        test();
    }
}
