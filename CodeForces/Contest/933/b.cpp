// Source: https://usaco.guide/general/io

#include<bits/stdc++.h>
using namespace std;
using ll = long long;


void test() {
    int n;
    cin >> n;
    vector<int>A(n, 0);
    for (int i = 0; i < n; ++i) cin >> A[i];
    // keep recursively doing it
    for (int i = 1; i < n - 1; ++i) {
        int prev = A[i - 1];
        int nxt = A[i + 1];
        // always try to make the prev equal to 0

        A[i] -= A[i - 1] * 2;
        A[i + 1] -= A[i - 1];
        A[i - 1] = 0;
        if (A[i + 1] < 0 || A[i] < 0) {
            cout << "NO\n";
            return;
        }
        // for (int j = 0; j < n; ++j) {
        // 	cout << A[j] << ' ';

        // }
        // cout << '\n';
    }
    for (int i = 0; i < n; ++i) {
        if (A[i] > 0 || A[i] < 0) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    return;

}

int main() {
    int n;
    cin >> n;
    while (n--) test();

    return 0;
}

