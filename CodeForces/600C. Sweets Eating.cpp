#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n, m;
    cin>> n >> m;
    vector<int>nums(n, 0);
    for (int i = 0; i  < n; ++i) cin >> nums[i];
    std::sort(nums.begin(), nums.end());
    vector<int>pref(n, 0);
    vector<int>ret(n, 0);
    for (int k = 0; k < n ; ++k) {
        pref[k] = pref[k -1] + nums[k];
    }
    ll cur = 0;
    for (int i = 0; i < n; ++i) {
        cur += nums[i];
        ret[i] = cur;
        if (i >= m) {
            ret[i] += ret[i - m];
        }
        cout << ret[i] << ' ';
    }




}
