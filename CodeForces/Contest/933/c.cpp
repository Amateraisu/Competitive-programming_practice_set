// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
using ll = long long;


void test() {
    // cout << "CALLED!\n";
    int n;
    cin >> n;
    string s;
    cin >> s;
    // cout << n << ' ' << s << '\n';
    ll res = 0;
    set<int>se;
    string s2;
    // cout << "BEFORE " << s << '\n';
    if (s.size() < 3) {
        cout << 0 << '\n';
        return;
    }
    vector<pair<int, int>>ps;
    for (int i = 0; i < n - 2; ++i) {
        // cout << s.substr(i, 3) << '\n';
        if (s.substr(i, 3) == "map" || s.substr(i, 3) == "pie") {
            ps.push_back(make_pair(i, i + 2));

        }
    }
    if (ps.empty()) {
        cout << 0 << '\n';
        return;
    }
    // cout << "INITIAL SIZE " << ps.size() << '\n';
    vector<pair<int, int>>p2;
    p2.push_back(ps[0]);
    for (int i = 1; i < ps.size(); ++i) {
        // cout << s[ps[i].first] << ' ' << s[p2.back().second] << '\n';
        if (ps[i].first == p2.back().second) {
            p2.back().second = ps[i].second;
        } else {
            p2.push_back(ps[i]);
        }
    }
    cout << p2.size() << '\n';


}

int main() {
    int n;
    cin >> n;
    while (n--) test();

    return 0;
}
