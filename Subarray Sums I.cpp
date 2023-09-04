#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
using ll = long long;

int main() {
    ll n, x;
    cin >> n >> x;
    vector<int> nums(n, -1);
    for (int i = 0; i < n ; i++) cin >> nums[i];
    map<ll,ll>mp;
    mp[0]++;
    ll res = 0;
    ll cur = 0;
    for (int i = 0; i < n; i++) {
        cur += nums[i];
        res += mp[cur - x];
        mp[cur]++;
    }
    cout << res << '\n';
    return 0;
}
