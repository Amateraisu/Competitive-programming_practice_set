#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
using ll = long long;
using namespace std;

int n, x;
int main() {
    cin >> n >> x;
    vector<ll>nums(x + 1, 0);

    vector<ll>coins(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    nums[0] = 1;
    int MOD = 1e9 + 7;
    for (int i = 0; i <=x; i++) {
        for (auto c : coins) {
            if (i - c >= 0) {
                nums[i] += nums[i - c] % MOD;
                nums[i] %= MOD;
            }
        }
    }
    cout << nums[x] << '\n';

    return 0;
}