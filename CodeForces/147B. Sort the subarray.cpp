#include <bits/stdc++.h>
using namespace std;

void test() {
    int n;
    cin >> n;
    vector<int>A(n, 0);
    vector<int>B(n, 0);
    for (int i = 0; i < n; ++i) cin >> A[i];
    for (int i = 0; i < n; ++i) cin >> B[i];
    int L = -1, R = -1;
    for (int i = 0; i < n; ++i) {
        if (A[i] != B[i]) {
            L = i;
            break;
        }
    }
    for (int i = n - 1; i>=0; --i) {
        if (A[i] != B[i]) {
            R = i;
            break;
        }
    }
    while (L > 0 && B[L] >= B[L - 1]) --L;

    while (R < n - 1 && B[R] <= B[R + 1]) ++R;
    cout << ++L << ' ' << ++R << '\n';
}

int main() {
    int n;
    cin >> n;
    while (n--) test();
}