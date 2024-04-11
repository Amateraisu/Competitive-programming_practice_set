#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void test() {
    ll n;
    cin >> n;
    int a = 1;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            a = n/i;
            break;
        }
    }
    cout << a << ' ' << n - a << '\n';
}


int main() {
    int n;
    cin >> n;
    while (n--) test();
}
