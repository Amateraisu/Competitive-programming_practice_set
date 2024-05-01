#include <bits/stdc++.h>
using namespace std;
using ll = long long;



void test() {
    using T = std::pair<ll, ll>;
    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    vector<T>A(a + 1);
    for (int i = 1; i <= a; ++i) {
        ll x, y;
        cin >> x >> y;
        A[i] = make_pair(x, y);
    }
    auto eu = [&](T& l, T& r) ->ll {
        return abs(l.first - r.first) + abs(l.second - r.second);
    };
    T first = A[c];
    T second = A[d];
    ll res = eu(first, second);
    if (b == 0) {
        cout << res << '\n';
        return;
    }
    vector<T>imp;
    for (int i = 1; i <= b; ++i) {
        imp.push_back(A[i]);
    }
    sort(imp.begin(), imp.end(), [&](T& a, T& b) {
        return eu(a, first) < eu(b, first);
    });
    // cout << first.first << ' ' << first.second << '\n';
    // cout << imp[0].first << ' ' << imp[0].second << '\n';
    ll fd = eu(imp[0], first);
    sort(imp.begin(), imp.end(), [&](T& a, T& b) {
        return eu(a, second) < eu(b, second);
    });

    ll sd = eu(imp[0], second);
    // cout << "FD SD " << fd << ' ' << sd << '\n';
    res = min(res, fd + sd);
    cout << res << '\n';

}

int main() {
    int n;
    cin >> n;
    while (n--) test();
}
