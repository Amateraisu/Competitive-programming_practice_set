#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll t;
void test() {
    ll n;
    cin >> n;
    if (n & (n - 1)) {
        // that means this is not a power of 2
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
