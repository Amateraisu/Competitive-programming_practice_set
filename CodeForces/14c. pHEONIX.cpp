#include <bits/stdc++.h>

using namespace std;

void test() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<int>nums(n, 0);
    vector<pair<int, int>>n2;
    for (int i = 0; i < n; ++i) cin >> nums[i];
    vector<int>t(n, 0);
    vector<int>heights(a, 0);
    int p1 = 0;
    for (int i = 0; i < n; ++i ) {
        n2.push_back(make_pair(nums[i], i));
    }
    sort(n2.begin(), n2.end());
    for (int i = 0; i < n; ++i) {
        t[i] = p1;
        ++p1;
        p1 %= a;
    }
    for (int i = 0; i < n; ++i) {
        heights[t[i]] += nums[i];
    }
    for (int i = 1; i < a; ++i) {
        if (abs(heights[i] - heights[i - 1]) > 3) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    for (int x : t) {
        cout << x << ' ';
    }
    cout << '\n';
}

int main() {
    int n;
    cin >> n;
    while (n--) test();
}
