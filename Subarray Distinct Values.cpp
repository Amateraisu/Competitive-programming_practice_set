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

    vector<ll> nums(n, 0);
    for (int i = 0; i < n; i++) cin >> nums[i];
    map<ll, ll>mp;
    mp[0]++;
    ll res = 0, cur = 0;
    set<ll>s;
    for (int i = 0; i < n; i++) {
        s.insert(nums[i]);
        cur = s.size();
        res += mp[cur - x];
        mp[cur]++;
    }

    cout << res << '\n';
    return 0;
}
