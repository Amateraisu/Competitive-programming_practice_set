#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void test() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    ll tot = 0;
    for (int x : nums) tot += x;
    if (tot % 3 == 0) {
        cout << 0 << '\n';
        return;
    }
    int most = 3 - (tot % 3);
    // is there a cout of numbers such that tot - these numbers divisible by 3 ?

    if (most == 2) {
        // is there one number ?
        for (int x : nums) {
            if ((tot - x) % 3 == 0) {
                cout << 1 << '\n';
                return;
            }
        }
        cout << 2 << '\n';
    } else {
        cout << 1 << '\n';

    }
    return;







}

int main() {
    ll t;
    cin >> t;
    while (t--) test();
}