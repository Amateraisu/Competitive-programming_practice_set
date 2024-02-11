#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    long long prod = 1;
    vector<int>ret(n + 1, 0);
    for (int i = 1; i <n; ++i) {
        if (std::gcd(i, n) == 1) {
            ret[i] = 1;
            prod = (prod * i) % n;
        }

    }
    int res = 0;
    for (int i = 0; i < n; ++i) {
        if (ret[i]) ++res;
    }
    cout << res << '\n';
    for (int i = 1; i < n; ++i) {
        if (ret[i]) {
            cout << i << ' ';
        }
    }
    cout << '\n';

}
