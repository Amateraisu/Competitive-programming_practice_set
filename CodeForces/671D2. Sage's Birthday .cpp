#include <bits/stdc++.h>
using namespace std;

constexpr int INF = 0x3f3f3f3f;
//vector<int> can(int n, vector<int>& nums) {
//    if (n * 2 + 1 > n) return {};
//    int total = nums.size();
//    int alloc = total - n;
//    vector<int>ret(total, INF);
//    int ptr = total - 1;
//    for (int i = 0, j = 0; i < total && j < alloc; j += 1, i += 2) {
//        ret[i] = nums[ptr];
//        --ptr;
//    }
//    for (int i = 0; i < n; ++i) {
//        if (ret[i] == INF) {
//            ret[i] = nums[ptr];
//            --ptr;
//        }
//    }
//    int res = 0;
//    for (int i = 1; i < n - 1; ++i) {
//        if (ret[i] < ret[i - 1] && ret[i] < ret[ i + 1]) ++res;
//    }
//    if (res >= n) return ret;
//
//    return {};
//}


int main() {
    int n;
    cin >> n;
    vector<int>nums(n, INF);
    vector<int>nums2;
    std::sort(nums.begin(), nums.end());
    int j = 0;
    for (int i = 1; i < n; i += 2) {
        nums2[i] = nums[j];
        ++j;
    }
    j = n - 1;
    for (int i = n- 1; i >= 0; i--) {
        if (nums2[i] == INF) {
            nums2[i] = nums[j];
            --j;
        }
    }
    int res = 0;
    for (int i = 1; i < n - 1; ++i) {
        if (nums2[i] < nums2[i - 1] && nums2[i] < nums2[i + 1]) ++res;
    }

    cout << res << '\n';
    for (int x : nums2) {
        cout << x << ' ' << '\n';
    }
    cout << '\n';
    return 0;
}
