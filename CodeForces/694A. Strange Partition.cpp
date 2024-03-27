#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void test() {
    int a, b;
    cin >> a >> b;
    vector<int>A(a, 0);
    for (int i = 0; i < a; ++i) cin >> A[i];
    ll cur = 0;
    ll res = 0;
    for (int x : A) cur += x;
    for (int x : A) {
        res += (x + b - 1)/b;
    }
    cout << (cur + b - 1)/b << ' ' << res << '\n';
}


int main() {
    int n;
    cin >> n;
    while (n--) test();
}
