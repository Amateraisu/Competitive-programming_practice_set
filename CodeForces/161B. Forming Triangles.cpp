#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll t;

void test() {
    int n;
    cin >> n;
    vector<int>nums(n, 0);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    map<ll, ll>mp;
    for (int x : nums) {mp[x]++;}
    ll sum = 0;
    ll tot = 0;
    for (auto& [a, b]: mp) {
        if (b >= 3) sum += b * (b - 1) * (b - 2)/6;
        if (b >= 2) sum += b * (b - 1)/2 * tot;


        tot += b;
    }
    cout << sum << '\n';
}

int main() {
    cin >> t;
    while (t--) test();
}
