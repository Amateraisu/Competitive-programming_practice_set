#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll t;


void test() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int res = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'B') {
            ++res;
        } else if (res > 0) {
            ++res;
        }
    }
    std::cout << res << '\n';

}
int main() {
    cin >> t;
    while (t--) test();
}