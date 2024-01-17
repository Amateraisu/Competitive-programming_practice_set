#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
ll t;
void solve() {
    int n;
    cin >> n;
    vector<ll>nums(n, 0);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    vector<int>num2;
    map<int, int>mp;
    map<int, int>mp2;
    for (int x: nums) ++mp[x];
    for (auto& [a, b]: mp) {
        num2.push_back(b);
    }
    ll res = INF;
    ll left = 0;
    right =
    sort(num2.begin(), num2.end());
    // then

    for (int x : num2) {

    }
    cout << res << '\n';

}

int main() {
    cin >> t;
    while (t--) solve();
}