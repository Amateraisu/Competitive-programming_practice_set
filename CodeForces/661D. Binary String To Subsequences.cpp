#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll t;
int n;
string s;
void solve() {
    cin >> n;
    cin >> s;
    int r = 0;
    vector<int>res(n, -1);
    vector<int>c0;
    vector<int>c1;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') {
            if (c1.size() == 0) {
                c0.push_back(c0.size() + 1);
                res[i] = c0.size();
            } else {
                int sub = c1.back();
                res[i] = sub;
                c1.pop_back();
                c0.push_back(sub);
            }
        } else {
            if (c0.size() == 0) {
                c1.push_back(c1.size() + 1);
                res[i] = c1.size();
            } else {
                int sub = c0.back();
                res[i] = sub;
                c0.pop_back();
                c1.push_back(sub);
            }

        }
        r = max(r, (int)c0.size());
        r = max(r, (int)c1.size());
    }
    cout << r << '\n';
    for (int i = 0; i < n; ++i) {
        cout << res[i] << ' ';
    }
    cout << '\n';
}

int main() {
    cin >> t;
    while (t--) solve();
}
