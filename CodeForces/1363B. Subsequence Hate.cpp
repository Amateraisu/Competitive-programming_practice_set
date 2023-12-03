#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll t;
string s;
void test() {
    cin >> s;
    ll c1 = 0, c0 = 0;
    ll res= 0x3f3f3f3f3f3f3f3f;
    for (int i = 0; i < s.size() ; ++i) {
        if (s[i] == '1') {
            ++c1;
        } else {
            ++c0;
        }
    }
    ll d1 = 0, d0 = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '1') {
            ++d1;
        } else {
            ++d0;
        }
        // 0000... 111...
        res = min(res, d1 + c0 - d0);
        res = min(res, d0 + c1 - d1);
    }
    cout << res << '\n';
}

int main() {
    cin >> t;
    while (t--) test();






    return 0;
}
