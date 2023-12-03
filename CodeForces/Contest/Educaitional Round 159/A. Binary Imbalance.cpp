#include <bits/stdc++.h>
using namespace std;

void test() {
    string s;
    int n;
    cin >> n;

    cin >> s;
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] != s[i - 1]) {
            cout << "YES\n";
            return;
        }
    }
    // that means they are all the same
    if (s[0] == '1') {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    return;

}

int main() {

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) test();
}
