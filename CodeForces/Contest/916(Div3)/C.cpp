#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll t, n, k, x;

void test() {
    cin >> n >> k;
    vector<ll>nums1(n, 0);
    vector<ll>nums2(n, 0);
    for (int i = 0; i < n; ++i) cin >> nums1[i];
    for (int i = 0; i < n; ++i) cin >> nums2[i];

    ll res= 0;
    ll maxi = 0;
    ll cur = 0;
    for (int i = 0; i < n; ++i) {
        ll n1 = nums1[i];
        cur += n1;
        ll n2 = nums2[i];
        maxi = max(n2, maxi);
        res = max(res, cur + (k - i - 1) * maxi);
    }
    cout << res << '\n';


}



int main() {
    cin >> t;
    while (t--) test();
}