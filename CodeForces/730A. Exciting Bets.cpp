#include <bits/stdc++.h>
#include <numeric>
using namespace std;
using ll = long long;
void test() {
    ll a, b;
    cin >> a >> b;
    if (a == b) {
        cout << 0 << ' ' << 0 << '\n';
        return;
    }
    ll g= abs(a - b);
    ll mini = min(a % g, g - a % g);
    cout << g << ' ' << mini << '\n';
    return;
}

int main() {
    int n;
    cin >> n;
    while (n--) test();
}