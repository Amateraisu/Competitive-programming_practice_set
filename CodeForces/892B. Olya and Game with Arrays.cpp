#include <bits/stdc++.h>
using namespace std;
using ll = long long;


void test() {
    int n, k , m;
    cin >> n >> k >> m;
    vector<ll>A(n, 0);
    for (int i = 0; i < n; ++i) cin >> A[i];
    int l = 0;
    ll res = 0;
    for (int r = 0; r < n; ++r) {
        if (A[r] > m) {
            l = r + 1;
        } else if (r - l + 1 >= k) {
            res += r - l + 1;

        }
    }
    cout << res << '\n';



}


int main() {
    int n;
    cin >> n;
    while (n--) test();
}