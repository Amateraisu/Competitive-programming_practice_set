#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll t;


void test() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int>nums1(n, 0);
    vector<int>v1(n, 0);
    vector<int>v2(m, 0);
    vector<int>nums2(m, 0);
    vector<int>v(k + 1, 0);
    map<int, int>c1;
    map<int, int>c2;
    for (int i = 0; i < n; ++i) cin >> nums1[i];
    for (int i = 0; i < m; ++i) cin >> nums2[i];
    if (n < k/2 || m < k/2) {
        cout << "NO\n";
        return;
    }
    // I will obviously try to take numbers which the other side doesnt have
    for (int x : nums1) ++c1[x];
    for (int x : nums2) ++c2[x];
    int p1 = k/2, p2 = k/2;
    // in here, get rid of the cases where im forced to take from 1 choice only
    for (int i = 1; i <= k; ++i) {
        // take the numbers which only exist once first
        if (c1[i] == 0 && c2[i] > 0) {
            if (p2 == 0) {
                std::cout << "NO\n";
                return;
            }
            --p2;
            v[i] = 1;
        } else if (c1[i] > 0 && c2[i] == 0) {
            if (p1 == 0) {
                std::cout << "NO\n";
                return;
            }
            --p1;
            v[i] = 1;
        } else if (c1[i] > 0 && c2[i] > 0 ){
            continue;
        } else {
            std::cout << "NO\n";
            return;
        }
    }
    // for the rest of the numbers, I can guaranteed to have both sides have.
    std::cout << "YES\n";

//    for (int i = 0; i < m; ++i) {
//        if (nums2[i] <= k && nums2[i] > 0 && c1[nums2[i]] == 0) {
//            v[nums2[i]] = 1;
//            --p2;
//        }
//    }




}
int main() {
    cin >> t;
    while (t--) test();
}

