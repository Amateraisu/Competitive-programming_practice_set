#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    int n, k;
    string s;
    cin >> n >> k;
    cin >> s;
    int l  = 0 ;
    int res = 0;
    int d = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'b') ++d;
        while (d > k) {
            if (s[l] == 'b') --d;
            ++l;
        }
        res = max(res, i - l + 1);
    }
    l = 0; d = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'a') ++d;
        while (d > k) {
            if (s[l] == 'a') --d;
            ++l;
        }
        res = max(res, i - l + 1);
    }
    cout << res << '\n';
}
