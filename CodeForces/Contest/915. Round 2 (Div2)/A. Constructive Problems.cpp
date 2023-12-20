#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int t, m, n;



void test() {
    cin >> m >> n;
    int res = min(m, n);
    res += max(m, n) - min(m ,n);
    cout << res << '\n';
}

int main() {
    cin >> t;
    while (t--) test();
}
