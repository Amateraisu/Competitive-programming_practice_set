#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll t;

void test() {
    string cur;
    cin >> cur;
    string c = string(1, cur[0]);
    // for the col
    for (int i = 1; i < 9; ++i) {
        if (i + '0' != cur[1]) {
            cout << c + to_string(i) << '\n';
        }
    }
    // for the current rows
    for (int i = 0; i < 8; ++i) {
        char row = i + 'a';
        if (row != cur[0]) {
            // cout << string(1, row) << " TESTING\n";
            // cout << "TESTING 2 "<< to_string(cur[1]) << '\n';
            cout << string(1, row) + string(1, cur[1]) << '\n';
        }
    }
}

int main() {
    cin >> t;
    while (t--) test();
}
