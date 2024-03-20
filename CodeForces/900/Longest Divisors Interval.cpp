#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    while (n--) {
        ll t;
        cin >> t;
        ll current = 0;
        ll ret = 0;
        for (int i = 1; i <= 1000; ++i) {
            if (n % i == 0) {
                ++current;
                ret = max(ret, current);
            } else {
                current = 0;
            }
        }
        cout << ret << '\n';
    }
}