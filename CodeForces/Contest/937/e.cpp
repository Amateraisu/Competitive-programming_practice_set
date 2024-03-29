#include <bits/stdc++.h>
using namespace std;


void test() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int>A;
    for (int i = 1; i * i < n; ++i) {
        if (s.size() % i == 0) {
            A.push_back(i);
            A.push_back(n / i);
        }
    }
    sort(A.begin(), A.end());
    auto diff = [&](int x) {
        string t = s.substr(0, x);

        string cur;
        int res = 0;

        for (int i = 0; i < n/x; ++i) cur += t;
        for (int i = 0; i < n; ++i) {
            if (s[i] != cur[i]) ++res;
        }

        return res;
    };

    auto diff2 = [&](int x) {
        if (2 * x > n) return 0x3f3f3f3f;
        string t = s.substr(x, x);
        int res = 0;
        string cur;
        for (int i = 0; i < n /x; ++i) cur += t;
        for (int i = 0; i < n; ++i) {
            if (s[i] != cur[i]) ++res;
        }


        return res;
    };
    for (int x : A) {
        if (diff(x) < 1 || diff2(x) < 1) {
            cout << x << '\n';
            return;
        }
    }
    cout << -1 << '\n';
}


int main() {
    int n;
    cin >> n;
    while (n--) test();
}