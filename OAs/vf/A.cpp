#include <bits/stdc++.h>

int main() {
    int maxi = 5000;
    int start = nums[0];
    int res = 0;
    vector<int>nums2;
    for (int i = 1; i < nums.size(); ++i) nums2.push_back(nums[i]);
    sort(nums.begin(), nums.end());
    for (int i = 0 ; i < nums2.size(), start <= maxi; ++i) {
        start += nums2[i];
        ++res;
    }
    return res;
}
