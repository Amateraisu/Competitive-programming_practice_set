#include <bits/stdc++.h>
using namespace std;
using ll = long long;


void test() {
    int n;
    cin >> n;
    vector<int>A(n, 0);
    vector<int>B(n, 0);
    for (int i = 0; i < n; ++i) cin >> A[i];
    for (int i = 0; i < n; ++i) cin >> B[i];
    int res = 0;
    unordered_map<int, int>cnt, cnt2;
    int l = 0;
    for (int i = 0; i < n; ++i) {
        if (A[i] != A[l]) {
            l = i;
        }
        cnt[A[i]] = max(cnt[A[i]], i - l + 1);
    }
    l = 0;
    for (int i = 0; i < n; ++i) {
        if (B[i] != B[l]) {
            l = i;
        }
        cnt2[B[i]] = max(cnt2[B[i]], i - l + 1);
    }
    for (auto& [a, b] : cnt) {
        res = max(res, b + cnt2[a]);
    }
    for (auto& [a, b] : cnt2) {
        res = max(res, b + cnt[a]);
    }
    cout << res << '\n';


}


int main() {
    int n;
    cin >> n;
    while (n--) test();
}
