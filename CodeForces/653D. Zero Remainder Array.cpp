#include <bits/stdc++.h>
using ll = long long;
using namespace std;
ll t;
int n, k;
void test() {
    cin >> n >> k;
    vector<int>nums(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    vector<int>need(n, 0);
    for (int i = 0; i < n; ++i) {
        need[i] = k - (nums[i] % k);

    }
    map<int, int>mp;
    for (int x: need) {
        if (x != 0 && x != k) ++mp[x];
    }
    ll cnt = 0;
    ll res = 0;
    for (auto& [a, b]: mp) {
        cnt = a + (b - 1LL) * k;
        res = max(res, cnt);
    }
    if (res) ++res;
    cout << res << '\n';


}

int main() {
    cin>>t;
    while (t--) test();
}
