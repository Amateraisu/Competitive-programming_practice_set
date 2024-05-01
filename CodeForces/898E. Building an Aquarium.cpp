#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void test() {
    ll n, k;
    cin >> n >> k;
    vector<ll>A(n, 0);
    for (int i = 0; i < n; ++i) cin >> A[i];
    ll l = 0;
    ll r = 1e10;
    auto can = [&](ll t) {
        ll need = 0;
        for (ll x : A) {
            need += max(0LL, t - x);
        }


        return need <= k;
    };
    ll res = -1;
    while (l <= r) {
        ll m = l + (r - l)/2;
        if (can(m)) {
            l = m + 1;
            res = m;

        } else {
            r = m - 1;
        }
    }
    cout << res << '\n';
}



int main() {
    int n;
    cin >> n;
    while (n--) test();
}
