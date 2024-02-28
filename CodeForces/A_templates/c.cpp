#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll t;


void test() {
    ll a, b, c;
    cin >> a >> b >> c;
    ll maxi = max(a, b);
    ll mini = min(a, b);
    if (a == b) {
        cout << log(c)/log(a) + 1 << '\n';
        return;
    }
    ll g = 0, l = 0;
    ll last = -1;
    ll t = c;
    while (t % maxi == 0) {
        ++g;
        t/=maxi;
    }
    t = c;
    while (t % mini == 0) {
        ++l;
        t/=mini;
    }
    // cout << l << ' ' << g << '\n';
    // cout << last << '\n';
    if (last == -1) {
        cout << 1 << '\n';
        return;
    }
    if (last % mini != 0) {
        cout << (l + 1) * (g + 1) + 1 << '\n';
    } else {
        cout << (l + 1) * (g + 1) << '\n';
    }




}
int main() {
    cin >> t;
    while (t--) test();
}