#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
void test() {
    int n;
    vector<int>nums(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];

    }
    ll mini = INF;
    int in = -1;
    for (int i = 0; i < n; ++i) {
        if (nums[i] < mini) {
            in = i;
            mini = nums[i];
        }
    }
    for (int i = in + 1; i < n; ++i) {
        if (nums[i] > nums[i - 1]) {
            cout << -1 << '\n';
            return;
        }
    }
    cout << in << '\n';
}


int main() {
    int n;
    cin >> n;
    while (n--) test();
}