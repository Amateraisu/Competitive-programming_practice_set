#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void test() {
    int n;
    string s;
    cin >> n;
    cin >> s;
    ll res = 0;
    auto can = [&](int t) -> bool {
        unordered_map<int, int>A;

        // increment if 0
        // decrement afterwards.
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            cnt += A[i];
            if (s[i] == '0' && (cnt % 2 == 0)) {
                ++cnt;
                A[i + t] -= 1;
            } else if (s[i] == '1' && (cnt % 2 != 0)) {
                ++cnt;
                A[i + t] -= 1;
            } else if (i + t > n) {
                break;
            }

        }
        cnt += A[n];

        return cnt == 0;
    };
    for (int i = 1; i <= n; ++i) {
        if (can(i)) {
            res = i;
        }

    }
    cout << res << '\n';

}
int main() {
    int n;
    cin >> n;
    while (n--) test();
}
