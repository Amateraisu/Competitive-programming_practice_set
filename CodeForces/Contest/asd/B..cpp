#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int t;
string s;
void test() {
    cin >> s;
    int z = 0, o = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] - '0' == 0) {
            ++z;
        } else {
            ++o;
        }
    }
    char ex;
    int ptr1 = abs(z - o);
    vector<int>st;
    if  (z > o) {
        ex = '0';
    } else {
        ex = '1';
    }
    int res = 0;
    int ptr2 = abs(z - o);
    while (ptr1 < s.size()) {
        if (ex == s[ptr1]) {
            ++res;

        }
        ++ptr1;

    }
    cout << res << '\n';
}

int main() {
    cin >> t;
    while (t--) test();
}
