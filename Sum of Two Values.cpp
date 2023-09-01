
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

int main() {
    long long x, t;
    cin >> x >> t;
    vector<int> nums(x, 0);
    for (int i = 0; i < x; i++) {
        cin >> nums[i];
    }
    map<int, int>mp;

    for (int i = 0; i < x; i++) {

        if (mp.find(t - nums[i]) != mp.end()) {
            cout << mp[t - nums[i]] << ' ' << i + 1 << '\n';
            return 0;
        }

        mp[nums[i]] = i + 1;
    }
    cout << "IMPOSSIBLE" << '\n';

    return 0;
}

