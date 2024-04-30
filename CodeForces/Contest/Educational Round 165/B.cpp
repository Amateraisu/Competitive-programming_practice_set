#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void test() {
    std::string s;
    cin >> s;
    int n = s.size();
    int curSize = 0;
    int i = 0;
    ll res = 0;
    while (i < n) {
        if (s[i] == '0') {
            if (curSize > 0) res += curSize + 1;
            ++i;
            continue;
        }
        // if I hit a 1,
        int j = i;
        while (j < n && s[j] == '1') ++j;
        curSize += j - i;
        i = j;
    }
    cout << res << '\n';

}

int main() {
    int n;
    cin >> n;
    while (n--) test();


    return 0;
}