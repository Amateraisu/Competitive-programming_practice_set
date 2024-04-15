#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void test() {
    ll n, k, b, s;
    cin >> n >> k >> b >> s;
    vector<ll>A(n, 0);

    A[0] = k * b;
    // cout << "FIRSt " << A[0] << '\n';
    ll cur = s - k * b;
    if (cur < 0) {
        cout << -1 << '\n';
        return;
    }
    for (int i = 0; i < n; ++i) {
        ll c = min(k - 1, cur);
        A[i] += c;
        cur -=c;
    }
    if (cur >= 1) {
        cout << -1 << '\n';
        return;
    }
    for (int i = 0; i < n; ++i) {
        cout << A[i] << ' ';
    }
    cout << '\n';





}

int main() {
    int n;
    cin >> n;
    while (n--) test();
}