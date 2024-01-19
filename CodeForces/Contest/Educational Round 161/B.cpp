#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll t;

void test() {
    int n;
    cin >> n;
    vector<int>nums(n, 0);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    map<int, int>mp;
    for (int x : nums) ++mp[x];
    vector<int>nums2;
    for (auto& [a, b]: mp) {
        nums2.push_back(b);
    }
    sort(nums2.begin(), nums2.end());
    int ptr1 = 0, ptr2 = nums2.size() - 1;
    while (ptr1 <= ptr2) {
        // even if they are on the same item it is okay
        bool left = false, right = false;
        if (nums2[ptr2] >= 2) {
            right = true;
            nums2[ptr2] -= 2;
        } else {
            --ptr2;
        }

        if (nums[ptr1] >= 1) {
            left = true;
            nums[ptr1] -= 1;
        } else {
            ++ptr1;
        }


    }

}

int main() {
    cin >> t;
    while (t--) test();
}
