#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll t;
ll n, P, l, p;

void test() {
    cin >> n >> P >> l >> p;
    ll c = ((n + 7 - 1)/7);
    // cout << c << " COUTN OF PRACS " << '\n';
    // try to squeeze and delay as much as possible
    ll days1 = (c + 2 - 1) / 2;
    ll cur1 = days1 * l + c * p;
    if (cur1 > P) {
        ll temp = days1;
        // do binary search here
        ll left = 0;
        ll right = days1;
        while (left <= right) {
            ll m = left + (right - left)/2;
            ll count = min(c, 2 * m);
            if (m * l + count * p >= P) {
                temp = m;
                right = m - 1;
            } else {
                left = m + 1;
            }
        }
        cout << n - temp << '\n';
        return;
    }
    // and if it is NOT, THEN
    ll temp = 0x3f3f3f3f3f3f3f3f;
    ll req = P - cur1;
    ll days = (req + l - 1)/ l;
    ll left = 0;
    ll right = days;
    // cout << "REQUIRED " << req << " days " << days << '\n';
    while (left <= right) {
        ll m = left + (right - left)/2;
        if (l * m >= req) {
            temp = m;
            right = m - 1;
        } else {
            left = m + 1;
        }
    }
    // cout << "MY TEMP " << temp << '\n';
    cout << n - temp - days1 << '\n';



}
int main() {
    cin >> t;
    while (t--) test();
}