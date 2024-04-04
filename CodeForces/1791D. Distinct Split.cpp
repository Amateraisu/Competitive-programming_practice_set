#include <bits/stdc++.h>
using namespace std;
using ll = long long;


void test() {
    int n;
    string s;
    cin >> n;
    cin >> s;
    vector<int>R(n, 0);
    set<char>se;
    ll res = 0;
    for (int i = n - 1; i >= 0; --i) {
        se.insert(s[i]);
        R[i] = se.size();
    }
    se.clear();
    for (int i = 0; i < n - 1; ++i) {
        ll t = R[i + 1];
        se.insert(s[i]);
        ll t2 = t + se.size();

        res = max(res, t2);
    }
    cout << res << '\n';

}


int main() {
//    freopen("Input.txt", "r", stdin);
//    freopen("Output.txt", "w", stdout);
//    freopen("Error.txt", "w", stderr);
    int n;
    cin >> n;
    while (n--) test();
}
