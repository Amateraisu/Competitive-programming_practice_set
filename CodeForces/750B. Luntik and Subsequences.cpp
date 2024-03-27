#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void test() {
    int n;
    cin >> n;
    vector<int>A(n, 0);
    for (int i = 0; i < n; ++i) cin >> A[i];
    int cnt0 = 0;
    int cnt1 = 0;
    for (int x : A) {
        if (x == 0) ++cnt0;
        if (x == 1) ++cnt1;
    }
    ll res = 0;
    for (int i = 0; i < cnt1; ++i) {
        res += (1LL << cnt0);
    }
    cout << res << "\n";
}



int main() {
    int t;
    cin >> t;
    while (t--) test();
}
