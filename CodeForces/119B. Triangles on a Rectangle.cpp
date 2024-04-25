#include <bits/stdc++.h>
using namespace std;
using ll = long long;



void test() {
    ll w, h;
    cin >> w >> h;
    ll a, b, c, d;
    cin >> a;
    vector<ll>A1(a, 0);
    for (int i = 0; i < a; ++i) cin >> A1[i];
    cin >> b;
    vector<ll>A2(b, 0);
    for (int i = 0; i < b; ++i) cin >> A2[i];
    cin >> c;
    vector<ll>A3(c, 0);
    for (int i = 0; i < c; ++i) cin >> A3[i];
    cin >> d;
    vector<ll>A4(d, 0);
    for (int i = 0; i < d; ++i) cin >> A4[i];
    sort(A1.begin(), A1.end());
    sort(A2.begin(), A2.end());
    sort(A3.begin(), A3.end());
    sort(A4.begin(), A4.end());
    ll res = 0;

    res = max(res, -1 * (A1[0] - A1[a - 1]) * h);
    res = max(res, -1 * (A2[0] - A2[b - 1]) * h);
    res = max(res, -1 * (A3[0] - A3[c - 1]) * w);
    res = max(res, -1 * (A4[0] - A4[d - 1]) * w);

    cout << res << '\n';



}

int main() {
    int n;
    cin >> n;
    while (n--) test();
}
