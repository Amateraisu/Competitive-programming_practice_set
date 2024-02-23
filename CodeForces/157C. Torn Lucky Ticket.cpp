#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int get(int x) {
    int ret = 0;
    while (x) {
        ret += x % 10;
        x /= 10;
    }
    return ret;
}


int main() {
    int n;
    cin >> n;
    ll res = 0;
    vector<int>nums(n, 0);
    for (int i = 0; i < n; ++i) cin>> nums[i];
    map<pair<int, int>, int>mp;
    for (int x: nums) {
        int p = x % 2;
        int sum = get(x);
        res += mp[make_pair(p, sum)];
        ++mp[make_pair(p, sum)];
    }
    cout << res << '\n';


}
