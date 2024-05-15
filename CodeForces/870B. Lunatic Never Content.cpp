#include <bits/stdc++.h>
using namespace std;


void test() {
    int n;
    cin >> n;
    vector<int>A(n, 0);
    for (int i = 0; i < n; ++i) cin >> A[i];
    using ll = long long;
    ll res = 0;
    int l = 0, r = n-1;
    while (l < r) {
        res = __gcd(res, 1LL *abs(A[l] - A[r]));
        ++l;
        --r;
    }
    cout << res << '\n';
}

int main() {
    int n;
    cin >> n;
    while (n--) test();
}