#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
using ll = long long;

int n, x;
int main() {
    cin >> n >> x;

    vector<int>nums(n);
    for (int i = 0 ; i < n; i++) cin >> nums[i];
    int r = -1;
    ll res = 0;
    map<int, int>mp;
    int c = 0;
    for (int l = 0; l < n; l++) {
        while (r < n - 1 && (c < x || mp[nums[r + 1]] >= 1)) {
            r++;
            mp[nums[r]]++;
            if (mp[nums[r]] == 1) c++;
        }
        res += (r - l + 1);
        mp[nums[l]]--;
        if (mp[nums[l]] == 0) c--;
    }

    cout << res << '\n';
    return 0;
}
