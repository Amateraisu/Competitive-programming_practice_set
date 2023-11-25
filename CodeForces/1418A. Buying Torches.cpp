#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll x, y, k;
ll t;

ll divide(ll a, ll b) {
    return (a + b - 1) / b;
}

void test_case() {
    scanf("%lld %lld %lld", &x, &y, &k);
    ll req = k + k * y - 1;
    ll gain = x-1;
    ll res = divide(req, gain);
    printf("%lld\n", res + k);
}

int main() {
    cin >> t;
    for (int i = 0; i < t; ++i) {
        test_case();
    }


    return 0;
}