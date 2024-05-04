#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void test() {
    int n, k;
    cin >> n >> k;
    vector<ll>A(n, 0);
    vector<ll>B(n, 0);
    vector<ll>C(n, 0);
    ll cur = 0;
    auto v = [&k](ll& c, ll t) -> bool {
        for (int i = 0; i < 60; ++i) {
            bool a =  ((1LL << i) & t);
            bool b = ((1LL << i) & k);
            if (a && !b) return false;
        }
        c |= t;
        return true;
    };
    for (int i = 0; i < n; ++i) cin >> A[i];
    for (int i = 0; i < n; ++i) cin >> B[i];
    for (int i = 0; i < n; ++i) cin >> C[i];
    for (int i = 0; i < n; ++i) {
        if (!v(cur, A[i])) break;
    }
    for (int i = 0; i < n; ++i) {
        if (!v(cur, B[i])) break;
    }
    for (int i = 0; i < n; ++i) {
        if (!v(cur, C[i])) break;
    }
    if (cur != k) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
    }

}

int main() {
    int n;
    cin >> n;
    while (n--) test();
}
