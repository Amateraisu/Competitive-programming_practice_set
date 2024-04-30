#include <bits/stdc++.h>
using namespace std;


void test() {
    int n;
    cin >> n;
    vector<int>A(n + 1, 0);
    for (int i = 1; i <= n; ++i) cin >> A[i];
    for (int i = 1; i <= n; ++i) {
        if (i == A[A[i]]) {
            cout << 2 << '\n';
            return;
        }
    }
    cout << 3 << '\n';

}

int main() {
    int n;
    cin >> n;
    while (n--) test();


    return 0;
}
