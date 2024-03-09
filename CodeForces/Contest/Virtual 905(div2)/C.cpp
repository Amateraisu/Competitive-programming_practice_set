#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void test() {
    int n;
    cin >> n;
    vector<int>A(n);
    vector<int>l(n, 0), f(n, 0);
    map<int, int>mp;
    for (int i = 0; i < n; ++i) cin >> A[i];
    for (int i = 0; i < n; ++i) {
        if (!mp[A[i]]) f[i] = 1;

        mp[A[i]] = 1;
    }
    mp.clear();
    for (int i = n - 1; i >=0; --i) {
        if (!mp[A[i]]) l[i] = 1;

        mp[A[i]] = 1;
    }
    ll res = 0;
    ll cnt = 0;
    for (int i = 0; i < n; ++i) {
        cnt += f[i];
        res += cnt * l[i];
    }
    cout << res << '\n';
}


int main() {
    int n;
    cin >> n;
    while (n--) test();
}