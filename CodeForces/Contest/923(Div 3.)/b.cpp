#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll t;


void test() {
    ll n;
    cin >> n;
    string res;
    vector<int>count(n, 0);
    vector<int>s(26, 0);
    for (int i = 0; i < n; ++i) cin >> count[i];
    for (int i = 0; i < n; ++i) {
        int need = count[i];
        for (int j = 0; j < 26; ++j) {
            // take one that is of need
            if (count[j] == need) {
                res += 'a' + j;
                ++s[j];
                break;
            }
        }
    }
    std::cout << res << '\n';
}
int main() {
    cin >> t;
    while (t--) test();
}