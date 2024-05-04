#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF = 0x3f3f3f3f3f3f3f3f;

void test() {
    int n, k;
    cin >> n >> k;
    vector<ll>A(n + 1, 0);
    for (int i = 1; i <= n; ++i) cin >> A[i];
    sort(A.begin(), A.end());
    ll t = 0;
    for (ll x : A) t += x;
    vector<ll>L(n + 2, 0);
    vector<ll>R(n + 2, 0);
    if (k == 0) {
        cout << t << '\n';
        return;
    }
    for (int i = 1; i <= n; ++i) {
        L[i] = L[i - 1] + A[i];
    }
    R[n + 1] = 0;
    for (int i = n ; i >= 1; --i) {
        R[i] = R[i + 1] + A[i];
    }
    ll mini = INF;
    // cout << "LEFT\n";
    // for (int x : L ) cout << x << ' ';
    // cout << '\n';
    // cout << "RIGHT\n";
    // for (int x : R) cout << x << ' ';
    // cout << '\n';
    // cout << "K IS " << k << '\n';
    for (int i = 0; i <= k; ++i) {
        int l = i;
        int r = k - i;
        mini = min(L[l * 2] + R[n + 1 - r], mini);
        mini = min(L[r * 2] + R[n + 1 - l], mini);
        // cout << "FIRST " << L[l * 2] << ' ' << R[r] << '\n';
        // cout << "SECOND " << L[r * 2] << ' ' << R[l] << '\n';
    }
    cout << t - mini << '\n';
}



int main() {
    int n;
    cin >> n;
    while (n--) test();
}
