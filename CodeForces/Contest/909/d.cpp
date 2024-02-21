#include <bits/stdc++.h>
using namespace std;
using ll = long long;


void test() {
    int n;
    cin >> n;
    vector<int>nums(n, 0);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    map<int, int>mp;
    ll res = 0;
    for (int x : nums) {
        if (x == 2) {
            res += mp[1];
        }
        if (x == 1) {
            res += mp[2];
        }
        res += mp[x];
        ++mp[x];
    }
    cout << res << '\n';
}



int main() {
    int n;
    cin >> n;
    while (n--) test();
}