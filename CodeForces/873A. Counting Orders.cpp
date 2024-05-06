#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void test() {
    int n;
    vector<ll>A(n, 0);
    vector<ll>B(n, 0);
    for (int i = 0; i < n; ++i) cin >> A[i];
    for (int i = 0; i < n; ++i) cin >> B[i];
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    ll res = 1;
    int MOD = 1e9 + 7;

    for (int i = 0; i < n; ++i) {
        auto p = std::lower_bound(B.begin(), B.end(), A[i]);
        if (p == B.end()) {
            cout << 0 << '\n';
            return;
        }
        ll pos = *p;
        --pos;
        res = (res * (pos)) % MOD;


    }
    cout << res << '\n';



}


int main() {
    int n;
    cin >> n;
    while (n--) test();
}
