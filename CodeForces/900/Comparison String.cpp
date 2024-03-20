#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void test() {
    string s;
    int n;
    cin >> n;
    cin >> s;
    ll current = 0;
    ll res = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '<') current = 0;
        if (s[i] == '>') ++current;

        res = max(res, current);
    }
    cout << res + 1 << '\n';



}


int main() {
    int n;
    cin >> n;
    while (n--) test();
}
