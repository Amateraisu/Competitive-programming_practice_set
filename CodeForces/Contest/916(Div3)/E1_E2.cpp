#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll t, n;

//void dfs(vector<ll>& n1, vector<ll>& n2, int turn) {
//
//}

void solve() {
    cin >> n;
    vector<ll>nums1(n, 0);
    vector<ll>nums2(n, 0);
    for (int i = 0; i < n; ++i) cin >> nums1[i];
    for (int i = 0; i < n; ++i) cin >> nums2[i];
    // does it matter whose turn it is?
    // nope..
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, less<pair<ll,ll>>>pq;
    ll res = 0;
    for (int i = 0; i < n; ++i) {
        if (nums1[i] > 0 && nums2[i] > 0) pq.push(make_pair(nums1[i] + nums2[i], i));

    }
    for (int i = 0; i < n; ++i) {
        auto p = pq.top(); pq.pop();
        if (i % 2 == 0) {
            // A's turn
            res += nums1[p.second];
            --res;
        } else {
            // B's turn
            res -= nums2[p.second];
            ++res;
        }

    }
    cout << res << '\n';

}

int main() {
    cin >> t;
    while (t--) solve();
}