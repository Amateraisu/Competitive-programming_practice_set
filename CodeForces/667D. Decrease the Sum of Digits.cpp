#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, s, t;

int sum(long long n) {
    int res = 0;
    while (n > 0) {
        res += n % 10;
        n /= 10;
    }
    return res;
}

void test() {
    cin >> n >> s;
    ll res = 0;
    if (sum(n) <= s) {
        cout << 0 << '\n';
        return;
    }
    ll pw = 1;
    for (int i = 0; i < 18; ++i) {
        int digit = (n / pw) % 10;
        ll add = pw * ((10 - digit) % 10);
        n += add;
        res += add;
        if (sum(n) <= s) break;
        pw *= 10;
    }
    cout << res << '\n';

}

int main() {
    cin >> t;
    while (t--) test();
}
