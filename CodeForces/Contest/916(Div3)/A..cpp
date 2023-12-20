#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int t;
int n;
void solve() {
    cin >> n;
    string s;
    cin >> s;
    int res = 0;
    map<char, int>mp;
    for (int i = 0; i < n; ++i) {
        ++mp[s[i]];
    }
    for (auto& [a, b]: mp) {
        if (b >= (a - 'A')) ++res;
    }
    cout << res << '\n';
}

int main() {
    cin >> t ;
    while (t--) solve();

}

