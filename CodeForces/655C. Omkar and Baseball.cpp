#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll t;

void test() {
    int n;
    cin >> n;
    vector<int>nums(n, 0);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    int c = 0;
    // find the first index that is wrong and the last index that is wrong
    int first = -1;
    int last = -1;
    for (int i = 0; i < n; ++i) {
        if (i + 1 != nums[i]) {
            if (first == -1) {
                first = i;
            }
            last = i;
        }
    }
    if (first == -1 && last == -1) {
        cout << 0 << '\n';
        return;
    }
    if (last - first + 1 == 1) {
        cout << 2 << '\n';
        return;
    }
    for (int i = first; i < last; ++i) {
        if (nums[i] == i + 1) ++c;
    }
    if (c > 0) {
        cout << 2 << '\n';
        return;
    } else if (c == 0) {
        cout << 1 << '\n';
    }
    cout << "Error lol\n";




}

int main() {
    cin >> t;
    while (t--) test();
}
