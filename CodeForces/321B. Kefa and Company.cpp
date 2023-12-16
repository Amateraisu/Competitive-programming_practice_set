#include <bits/stdc++.h>

using ll = long long;
using namespace std;
ll n, m, a, b;

int main() {
    cin >> n >> m;
    vector<pair<ll, ll>>nums;
    for (int i = 0 ; i< n; ++i) {
        cin >> a >> b;
        nums.push_back(make_pair(a, b));
    }
    auto c = [&](pair<ll, ll>& a, pair<ll, ll>& b) {
        return a.first < b.first;
    };
    sort(nums.begin(), nums.end(), c);
    int l = 0;
    ll res = 0;
    ll cur = 0;
    for (int i = 0; i < n; ++i) {
        cur += nums[i].second;
        while (nums[i].first - nums[l].first > m) {
            cur -= nums[l].second;
            ++l;
        }
        res = max(res, cur);
    }
    cout << res << '\n';




    return 0;
}