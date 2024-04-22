#include <bits/stdc++.h>
using namespace std;

void test() {
    using ll = long long;
    int n, k;
    string s;
    cin >> n >> k;
    cin >> s;
    int c = 0;
    int l = 0;
    ll res = 0x3f3f3f3f3f3f3f3f;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'W') {
            ++c;
        }
        if (i - l + 1 > k) {
            if (s[l] == 'W') --c;
            ++l;
        }
        if (i - l + 1 == k) {
            res = min(res, 1LL * k - c);
        }
    }
    cout << res << '\n';

}

int main() {
    int n;
    cin >> n;
    while (n--) test();
}