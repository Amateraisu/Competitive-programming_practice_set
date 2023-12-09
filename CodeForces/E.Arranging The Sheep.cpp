#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll t;
ll n;
string s;
constexpr ll INF = 0x3f3f3f3f3f3f3f3f;

void test()  {
    cin >> n;
    cin >> s;
    vector<ll>l(n, 0);
    vector<ll>r(n, 0);
    ll res = INF;
    ll cur = 0;
    ll cost = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '*') {
            l[i] = cost;
            ++cur;
        } else {
            cost += cur;
        }
    }
    cur = 0;
    cost = 0;
    for (int i = n - 1; i >=0 ; --i) {
        if (s[i] == '*') {
            ++cur;
            r[i] = cost;
        } else {
            cost += cur;
        }
    }
    if (cost == 0) {
        cout << 0 << '\n';
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (s[i] == '*') res = min(res, l[i] + r[i]);

    }
    cout << res << '\n';
}

int main() {
    cin >> t;
    while (t--) test();





    return 0;
}
