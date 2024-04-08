#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void test() {
    int n;
    string s;
    cin >> n;
    cin >> s;
    ll res = 0;
    auto can = [&](int t) -> bool {
        map<int, int>A;
        bool set = false;
        for (int i = 0; i < n; ++i) {
            if (A[i] == 1) set = false;
            if (!set) {
                if (s[i] == '1') {
                    continue;
                } else {
                    set = true;
                    A[i + t] = 1;
                }
            } else {
                if (s[i] == '1') {
                    return false;
                } else {
                    continue;
                }
            }


        }
        if (A[n] == 1) set = false;
        return set == false;
    };
    for (int i = 1; i <= n; ++i) {
        if (can(i)) {
            res = i;
        }

    }
    cout << res << '\n';

}
int main() {
    int n;
    cin >> n;
    while (n--) test();
}
