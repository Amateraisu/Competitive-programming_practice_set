#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
using ll = long long;
using namespace std;
ll n, x;
vector<ll>nums;

ll dfs(int l, int r, bool A) {
    if (l < r) return 0;

    ll res = 0;
    if (A) {
        res = max(dfs(l + 1, r, false) + nums[l], dfs(l, r - 1, false));

    } else {
        res = min(dfs(l + 1, r, true) + nums[l], dfs(l, r - 1, true));
    }


    return res;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        nums.push_back(x);
    }


    ll res = dfs(0, n - 1, 0);
    cout << res << '\n';
    return 0;
}
