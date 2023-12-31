#include <bits/stdc++.h>
using namespace std;

string s;
int k;
int t;
void solve() {
    cin  >> s;
    cin >> k;
    int n = s.size();
    string res('1', n);
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') {
            if (i - k >= 0) res[i - k] = 0;
            if (i + k < n) res[i - k] = 0;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            if (!((i - k >= 0 && res[i - k] == '1') || (i + k < n && res[i + k] == '1'))) {
                cout << -1 << '\n';
                return;
            }
        }
    }
    cout << res << '\n';
    return;

}


int main() {
    cin >> t;
    while (t--) solve();
}
