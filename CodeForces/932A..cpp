#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll t;


void test() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string s2 = s;
    reverse(s.begin(), s.end());
    if (s2 <= s) {
        cout << s2 << '\n';
    } else {
        // spend one operation to reverse it;
        cout << s + s2 << '\n';
    }

    return;

}
int main() {
    cin >> t;
    while (t--) test();
}