#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int t;

void solve() {
    int n;
    cin >> n;
    int res = 0;
    for (int i = 3; i * i <= 2*n - 1; i += 2) ++res;
    cout << res << '\n';

}

int main() {
    cin >> t;
    while (t--) solve();
}