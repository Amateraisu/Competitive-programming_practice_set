#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n, m;


int main() {
    cin >> n >> m;
    vector<int>nums(n, 0);
    nums[n - 1] = 1;
    --m;
    for (int i = 0; i < n - 1; ++i) {
        if (m) {
            nums[i] = 1;
            --m;
        }
    }
    if (m) nums[n -1] += m;
    int tot = 0;
    for (int i = 0; i < n; ++i) {
        if (nums[i] == 1) ++tot;
    }
    if (nums[n - 1] - tot > 1) {
        cout <<"YES\n";
        for (int i = 0; i < n; ++i) cout << nums[i] << ' ';
        cout << '\n';
        cout << nums[n - 1] - 1 << '\n';
    } else {
        cout << "NO\n";
    }
}