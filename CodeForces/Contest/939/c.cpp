#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void print(int n) {
    for (int i = 1; i <= n; ++i) {
        cout << i << ' ';
    }
    cout << '\n';
}


void test() {
    ll n;
    cin >> n;
    ll res = 0;
    ll cnt = 2* n - 1;
    ll k = 2 * (n - 1) + 1;
    for (int i = n; i >=  1; --i) {
        res += i * (cnt);
        cnt -= 2;
    }
    cout << res << ' ' << k << '\n';
    cout << 1 << ' ' << n << ' ';
    print(n);
    for (int i = n - 1; i >= 1; --i) {
        cout << 1 << ' ' << i << ' ';
        print(n);
        cout << 2 << ' ' << i << ' ';
        print(n);
    }






}




int main() {
    int n;
    cin >> n;
    while (n--) test();
}
