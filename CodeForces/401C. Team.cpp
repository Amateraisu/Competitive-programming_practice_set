#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll zeros, ones;


int main() {


    cin >> zeros >> ones;

    if (zeros == ones) {
        for (int i = 0; i < zeros; ++i) {
            cout << 1 << 0;
        }
    } else if (zeros > ones) {
        if (zeros > ones + 1) {
            cout << -1 << '\n';
            return 0;
        }
        cout << 0;
        for (int i = 0; i < ones ; ++i) {
            cout << 1 << 0;
        }
    } else {
        if (ones > (zeros * 2 + 2)) {
            cout << -1 << '\n';
            return 0;
        }
        for (int i = zeros; i > 0; --i) {
            // start with 1
            if (ones > i) {
                cout << 11;
                cout << 0;
                ones -= 2;
            } else {
                cout << 10;
                --ones;
            }
            // cout << "LEFT " << zeros << ' ' << ones << '\n';
        }
        if (ones == 1) cout << 1 << '\n';
        if (ones == 2) cout << 11<<'\n';
    }
    return 0;
}
