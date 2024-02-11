#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll t;


void test() {
    int a, b;
    cin >> a >> b;
    if (a % 2 != 0 && b % 2 != 0) {
        cout << "NO\n";
        return;
    }
    // try cutting a
    if (a % 2 == 0) {
        int na = a / 2;
        int nb = b * 2;
        if (min(na, nb)!= min(a, b) || max(na, nb) != max(a, b)) {
            cout << "YES\n";
            return;
        }
    }
    if (b % 2 == 0) {
        int na = a * 2;
        int nb = b/2;
        if (min(na, nb)!= min(a, b) || max(na, nb) != max(a, b)) {
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
    return;

}
int main() {
    cin >> t;
    while (t--) test();
}