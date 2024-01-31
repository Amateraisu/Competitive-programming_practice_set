#include <bits/stdc++.h>
using namespace std;



int main() {
    int n;
    cin >> n;
    int a, b;
    cin >> a;
    deque<int>nums1(a, 0);
    for (int i = 0; i < a; ++i) cin >> nums1[i];
    cin >> b;
    deque<int>nums2(b, 0);
    for (int i = 0; i < b; ++i) cin >> nums2[i];
    set<pair<int, int>>s;
    int rounds = 0;
    while (!nums1.empty() && !nums2.empty()) {
        int n1 = nums1.front(); nums1.pop_front();
        int n2 = nums2.front(); nums2.pop_front();
        if (rounds >= 100000) {
            std::cout << -1 << '\n';
            return 0;
        }
        if (n1 > n2) {
            nums1.push_back(n2);
            nums1.push_back(n1);
        } else {
            nums2.push_back(n1);
            nums2.push_back(n2);
        }
        ++rounds;


    }
    std::cout << rounds << ' ';
    if (!nums1.empty()) {
        std::cout << 1 << '\n';
    } else {
        cout << 2 << '\n';
    }


}