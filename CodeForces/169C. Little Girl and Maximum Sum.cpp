#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, m, a, b;
int main() {
    cin >> n >> m;
    // 1 based -indexing
    vector<ll>nums(n, 0);
    vector<ll>diff(n + 2, 0);
    for (int i = 0 ; i < n; ++i) {
        cin >> nums[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        ++diff[a];
        --diff[b + 1];
    }
    ll cur = 0;
    vector<ll>magnitude(n + 2, 0);
    for (int i = 0; i < n + 2; ++i) {
        cur += diff[i];
        magnitude[i] = cur;
    }
    auto c = [&](int a , int b) {return a > b;};
    sort(nums.begin(), nums.end(), c);
    sort(magnitude.begin(), magnitude.end(), c);
    ll res = 0;
    for (int i = 0; i < n; ++i) {
        res += magnitude[i] * nums[i];
    }
    cout << res << '\n';



}
