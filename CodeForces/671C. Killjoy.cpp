#include <bits/stdc++.h>
using namespace std;


using ll = long long;

ll t;


void test() {
    int n, x;
    cin >> n >> x;
    vector<int>nums(n, 0);
    for (int i = 0; i < n; ++i)cin >> nums[i];
    bool flag = true;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (nums[i] != x) flag = false;
        cnt += (nums[i] == x);
    }
    if (flag) {
        cout << 0 << '\n';
        return;
    }
    // the case with 1 change
    ll tot = 0;
    for (int i = 0; i < n; ++i) {
        tot += nums[i] - x;
    }
    if (tot == 0) {
        cout << 1 << '\n';
        return;
    }
    if (cnt > 0) {
        cout << 1 <<  '\n';
        return;
    }
    cout << 2 << '\n';
    return;

}

int main() {
    cin >> t;
    while (t--) test();
}
