#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll t;

void test() {
    int n;
    cin >> n;
    int index = -1;
    vector<int>nums(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
        if (nums[i] == 0) {
            cout << 0 << '\n';
            return;
        }
    }
    int c = 0;
    for (int i = 0; i < n; ++i) {
        if (nums[i] < 0) {
            ++c;
            index = i;
        }
    }
    if (c % 2 == 0 && index != -1) {
        cout << 1 << '\n';
        cout << index + 1 << ' ' << 0 << '\n';
    } else if (c % 2 != 0) {
        cout << 0 << '\n';
    } else {
        cout << 1 << '\n';
        cout << 1 << 0 << '\n';
    }
}


int main() {
    cin >> t;
    while (t--) test();
}
