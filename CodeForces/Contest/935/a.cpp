#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
void test() {
    ll a, b;
    cin >> a >> b;
    vector<ll>A(a, 0);
    vector<ll>B(a, 0);
    for (int i = 0; i < a; ++i) cin >> A[i];
    for (int i = 0; i < a; ++i) cin >> B[i];
    ll cheapest = 0;
    ll res = INF;
    for (int i = b; i < a; ++i) {
        cheapest += min(A[i], B[i]);
    }
    for (int i = b - 1; i >= 0; --i) {
        res = min(res, cheapest + A[i]);
        cheapest += min(A[i], B[i]);
    }
    cout << res << '\n';

}

int main() {
    int n;
    cin >> n;
    while (n--) test();
}




