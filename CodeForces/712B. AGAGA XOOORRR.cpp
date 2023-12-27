#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll t;


void test() {
    int n;
    cin >> n;
    vector<int>nums(n, 0);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    // the aa case
    int cur = 0;
    for (int i = 0 ; i< n; ++i) cur ^= nums[i];
    if (cur == 0) {
        cout << "YES\n";
        return;
    }
    // now the aaa case
    vector<int>pre(n, 0);
    vector<int>post(n, 0);
    cur = 0;
    for (int i = 0; i< n; ++i) {
        cur ^= nums[i];
        pre[i] = cur;
    }
    cur = 0 ;
    for (int i = n - 1; i >= 0; --i) {
        cur ^= nums[i];
        post[i] = cur;
    }
    for (int i = 1; i < n - 1; ++i) {
        for (int j = i; j < n - 1; ++j) {
            if (pre[i - 1] == pre[j] && pre[j] == post[j + 1]) {
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";
    return;
}

int main() {
    cin >> t;
    while (t--) test();
}