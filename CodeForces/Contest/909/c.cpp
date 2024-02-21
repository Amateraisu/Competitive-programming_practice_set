#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
void test() {
    int n;
    cin >> n;
    vector<int>nums(n, 0);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    ll t = 0;
    ll cur = -INF;
    int prev = 0;
    for (int i = 0 ; i < n; ++i) {
        if (prev == 0) {
            t += nums[i];
            if (nums[i] % 2 == 0) {
                prev = 1;
            }  else {
                prev = -1;
            }
        } else if (prev == 1) {
            if (nums[i] % 2 != 0) {
                t+= nums[i];
                prev = -1;
            } else {
                t = nums[i];
                prev = 1;
            }
        } else {
            // prev is -1;
            if (nums[i] % 2 == 0) {
                t += nums[i];
                prev = 1;
            } else {
                t = nums[i];
                prev = -1;
            }
        }
        cur = max(t, cur);
        if (t < 0) {
            t = 0;
            prev = 0;
        }


        // cout << "currently " << t << '\n';
    }
    cout << cur << '\n';
}


int main() {
    int n;
    cin >> n;
    while (n--) test();
}