#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll t;

void test() {
    int n;
    cin >> n;
    vector<int>nums(n, 0);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    vector<ll>suffix(n + 1, 0);
    for (int i = n - 1; i >= 0; --i) {
        suffix[i] = suffix[i + 1] + nums[i];
    }
    ll res = suffix[0];
    for (int i = 1; i < n; ++i) {
        if (suffix[i] > 0) res += suffix[i];
    }
    cout << res << '\n';


}
int main() {
    cin >> t;
    while (t--) test();



    return 0;
}

