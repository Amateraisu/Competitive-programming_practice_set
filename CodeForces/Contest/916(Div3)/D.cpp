#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll t;
ll n;
ll x;
void solve() {
    cin >> n;
    vector<pair<ll,ll>>nums1(n);
    vector<pair<ll, ll>>nums2(n);
    vector<pair<ll, ll>>nums3(n);
    auto c = [&](auto a, auto b) {
        return a.first > b.first;
    };
    for (int i = 0; i < n; ++i) {
        cin >> x;
        nums1[i] = make_pair(x, i);
    }
    for (int i = 0; i < n; ++i) {
        cin >> x;
        nums2[i] = make_pair(x, i);
    }
    for (int i = 0; i < n; ++i) {
        cin >> x;
        nums3[i] = make_pair(x, i);
    }
    sort(nums1.begin(), nums1.end(), c);
    sort(nums2.begin(), nums2.end(), c);
    sort(nums3.begin(), nums3.end(), c);
    ll res = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                if (nums1[i].second == nums2[j].second || nums1[i].second == nums3[k].second || nums2[j].second == nums3[k].second) continue;
                res = max(nums1[i].first + nums2[j].first + nums3[k].first, res);
            }
        }
    }
    cout << res << '\n';


}


int main() {
    cin >> t;
    while (t--) solve();



    return 0;
}