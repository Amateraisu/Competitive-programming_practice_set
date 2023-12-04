#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n;

int main() {
    cin >> n;
    vector<ll>f;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            ll cur = 1;
            while (n % i == 0) {
                n /=i;
                cur *= i;
            }
            f.push_back(cur);
        }
    }
    ll a = 0x3f3f3f3f3f3f3f3f;
    ll b = 0x3f3f3f3f3f3f3f3f;
    if (n > 1) f.push_back(n);
    for (int i = 0; i < (1 << f.size()); ++i) {
        ll at = 1;
        ll bt = 1;
        for (int j = 0; j < n; ++j) {
            if (1 & (i >> j)) {
                at *= f[j];
            } else {
                bt *= f[j];
            }
        }
        if (max(at , bt) < max(a, b)) {
            a = at;
            b = bt;
        }

    }
    cout << a << " " << b << '\n';



    return 0;
}
