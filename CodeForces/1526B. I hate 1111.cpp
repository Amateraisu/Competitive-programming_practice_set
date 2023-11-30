#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll t;


ll num;

int main() {
    cin >> t;
    constexpr int core = 111 * 11 - 111 -11;
    for (int i = 0; i < t; ++i) {
        cin >> num;
        if (num > core) {
            cout << "YES\n";
        } else if (num == 1099) {
            cout << "NO\n";
        } else {
            int k1 = num % 11;
            int k2 = num / 111;
            if (k2 >= k1) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }

}
