#include <bits/stdc++.h>
using namespace std;
using ll = long long;


void test() {
    ll n, x;
    cin >> n >> x;
    vector<ll>A(n, 0);
    for (int i = 0; i < n; ++i) cin >> A[i];
    ll l = A[0];
    ll r = A[0];
    ll res = 0;
    for (int i = 0; i < n; ++i) {
        l = min(A[i], l);
        r = max(A[i], r);
        if (r - l > x * 2) {
            ++res;
            l = A[i];
            r = A[i];
        }
    }
    cout << res << '\n';
}


int main() {
    int n;
    cin >> n;
    while (n--) test();
}
