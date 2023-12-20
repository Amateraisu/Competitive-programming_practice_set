#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll t;
string s;
void test() {
    cin >> s;
    int first = s[0] - '0';
    int ptr1 = 1;
    while (ptr1 < s.size() && s[ptr1] - '0' == 0) {
        ++ptr1;
        first *= 10;
    }


    int second = 0;
    for (int i = ptr1 ; i < s.size(); ++i) {
        second *= 10;
        second += s[i] - '0';
    }

    if (first == second || second <= first) {
        cout << -1 << '\n';
    } else {
        cout << first << ' ' << second << '\n';
    }


}

int main() {
    cin >> t;
    while (t--) test();
}