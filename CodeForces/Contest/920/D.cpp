#include <bits/stdc++.h>
using namespace std;
using ll = long long;


ll t;

void test() {
    int n, m;
    cin >> n >> m;
    vector<ll>nums1(n, 0);
    vector<ll>nums2(m, 0);
    int ptr1 = 0, ptr2 = m - 1;
    for (int i = 0; i < n ;++i) cin >> nums1[i];
    for (int i = 0; i < m; ++i) cin >> nums2[i];
    std::sort(nums1.begin(), nums1.end());
    std::sort(nums1.begin(), nums2.end());
    ll res = 0;
    for (int i = 0; i < n; ++i) {
        int num1 = nums1[i];
        if (abs(num1 - nums2[ptr1]) > abs(num1 - nums2[ptr2])) {
            // use ptr1
            res += abs(num1 - nums2[ptr1]);
            ++ptr1;
        } else {
            res += abs(num1 - nums2[ptr1]);
            ++ptr2;
        }


    }
    cout << res << '\n';
}

int main() {
    cin >> t;
    while (t--) test();
}