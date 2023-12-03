#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll t;
ll n;
ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a %b);
}
void test() {
    cin >> n;
    vector<int>d(n, 0);
    for (int i = 0; i < n; ++i) cin >> d[i];
    ll maxi = *max_element(d.begin(), d.end());
    ll cur = maxi - d[0];
    for (int i = 1; i < n; ++i) {
        ll diff = maxi - d[i];
        if (diff > 0) cur = gcd(cur, diff);
    }
    ll res =0;
    for (int x : d) {
        ll diff = maxi - x;
        res += diff / cur;
    }
    cout << res << '\n';

}

int main() {
    cin >> t;
    while (t--) test();


    return 0;
}