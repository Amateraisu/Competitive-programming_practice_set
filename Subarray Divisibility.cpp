#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
using ll = long long;

int n, x;
int main() {
    cin >> n;

    vector<ll> nums(n, 0);
    for (int i = 0; i < n; i++) cin >> nums[i];
    map<ll, ll>mp;
    mp[0]++;
    ll res = 0, cur = 0;
    for (int i = 0; i < n; i++) {
        cur+= nums[i], cur %= n;
        if (cur < 0) cur += n;
        res += mp[cur];
        mp[cur]++;
    }

    cout << res << '\n';
    return 0;
}
