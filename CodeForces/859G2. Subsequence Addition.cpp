#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void test() {
    int n;
    cin >> n;
    vector<int>A(n, 0);
    for (int i =0; i < n; ++i) cin >> A[i];

    sort(A.begin(), A.end());
    ll cur = 1;
    if (A[0] != 1) {
        cout << "NO\n";
        return;
    }
    for (int i = 1; i < n; ++i) {
        if (cur < A[i]) {
            cout << "NO\n";
            return;
        }
        cur += A[i];
    }

    cout << "YES\n";
    return;

}


int main() {
    int n;
    cin >> n;
    while (n--) test();
}
