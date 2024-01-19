#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int t;
void test() {
    int n;
    string a, b, c;
    cin >> n;
    cin >> a;
    cin >> b;
    cin >> c;
    bool can = false;
    for (int i = 0; i < n; ++i) {
        if (c[i] != a[i] && c[i] != b[i]) can = true;
    }
    if (can) {
        cout << "YES\n";

    } else {
        cout << "NO\n";
    }
    return;
}

int main() {
    cin >> t;
    while (t--) test();
}
