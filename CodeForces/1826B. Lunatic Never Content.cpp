#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void test() {
    int n;
    cin >> n;
    vector<ll>A(n, 0);
    for (int i = 0; i < n; ++i) cin >> A[i];
    int p1 = 0;
    int p2 = n - 1;
    ll res = 0;
    while (p1 <= p2) {
        res = __gcd(res, abs(A[p1] - A[p2]));
        ++p1;
        --p2;
    }
    cout << res << '\n';




}


int main() {
    int n;
    cin >> n;
    while (n--) test();
}
