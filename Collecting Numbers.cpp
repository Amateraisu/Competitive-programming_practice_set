#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;
int n, x;
int main() {
    cin >> n;
    vector<vector<int>> nums(n);
    for (int i = 0 ; i < n ; i++) cin >> x, nums[i] = {x, i};
    sort(nums.begin(), nums.end());
    int res = 1;
    for (int i = 1; i < n; i++) {
        if (nums[i][1] < nums[i - 1][1]) res++;
    }
    cout << res << '\n';
    return 0;
}