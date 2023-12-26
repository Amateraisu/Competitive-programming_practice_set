#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int l, r;
ll t;

void solve() {
    cin >> l >> r;
    int res = 0;
    while (l != 0 || r != 0) {
        res += r - l;
        r/=10;
        l /=10;
    }
    cout << res << '\n';
}

int main() {
    cin >> t;
    while (t--) solve();
}