#include <bits/stdc++.h>
using namespace std;
using p = pair<int, char>;  // Change to pair

using ll = long long;
ll t;
ll n;
void test() {
    string st;
    cin >> n;
    cin >> st;
    vector<int>c(26, 0);
    for (char ch: st) {
        // cout << ch << '\n';
        // cout << ch - '0' << '\n';
        ++c[ch - 'a'];
    }

    priority_queue<int>s;

    for (int i = 0; i < 26; ++i) {
        if (c[i] > 0) s.push(c[i]);

    }
    while (s.size() > 1) {
        int most1 = s.top();
        s.pop();
        int most2 = s.top();
        s.pop();
        --most1;
        --most2;

        if (most1 > 0) s.push(most1);
        if (most2 > 0) s.push(most2);

    }
    int res = 0;
    while (!s.empty()) {
        res += s.top();
        s.pop();
    }
    cout << res << '\n';
}

int main() {
    cin >> t;
    while (t--) test();
    return 0;
}
