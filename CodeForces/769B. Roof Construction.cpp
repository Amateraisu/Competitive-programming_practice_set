#include <bits/stdc++.h>
using namespace std;
using ll = long long;



void test() {
    int n;
    cin >> n;
    int nxt;
    vector<int>A(n + 1, 0);
    A[n] = 1;
    if (n % 2 == 0) {
        // unset the left most bit
        for (int i = 31; i >= 0; --i) {
            if ((1 << i) & n == 1) {
                nxt = n ^  (1 << i);
                A[nxt] = 1;
                break;
            }
        }
        cout << n << ' ' << nxt << ' ';
        for (int i = 0; i < n; ++i) {
            if (A[i] == 0) cout << i << ' ';
        }
    } else {
        nxt = n - 1;
        cout << n << ' ' << nxt << ' ';
        A[nxt] = 1;
        for (int i = 0; i < n; ++i) {
            if (A[i] == 0) {
                cout << A[i] << ' ';
            }
        }
    }
    cout << '\n';


}

int main() {
    int n;
    cin >> n;
    while (n--) test();
}
