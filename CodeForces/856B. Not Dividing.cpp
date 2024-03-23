#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void test() {
    int n;
    cin >> n;
    vector<int>A(n, 0);
    for (int i = 0; i < n; ++i) cin >> A[i];
    if (A[0] == 1) ++A[0];
    for (int i = 1; i < n; ++i) {
        if (A[i] == 1) ++A[i];
        if (A[i] % A[i - 1] == 0) ++A[i];
        if (A[i] % A[i - 1] == 0) ++A[i];

    }
    for (int i = 0; i < n; ++i) {
        cout << A[i] << ' ';
    }
    cout << '\n';
}

int main() {
    int n;
    cin >> n;
    while (n--) test();
}
