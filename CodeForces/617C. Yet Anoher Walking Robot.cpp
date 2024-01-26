#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
void test() {
    int n;
    string s;
    cin >> n;
    cin >> s;
    map<pair<int, int>, int>mp;
    int r = 0, c = 0;
    ll res = INF;
    int left = 0, right = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'L') --c;
        if (s[i] == 'R') ++c;
        if (s[i] == 'U') --r;
        if (s[i] == 'D') ++r;
        if (mp.find(make_pair(r, c)) != mp.end()) {
            res = min(res, 1LL * i - mp[make_pair(r, c)] + 1);
            left = mp[make_pair(r, c)] + 1;
            right = i + 1;
        }
        mp[make_pair(r, c)] = i;
    }
    if (res == INF) {
        cout << -1 << '\n';
    } else {
        cout << left << ' ' << right << '\n';
    }

}

int main() {
    ll t;
    cin >> t;
    while (t--) test();
}


