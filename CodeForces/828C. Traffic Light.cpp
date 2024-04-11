#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void test() {
    int n;
    char c;
    string s;
    cin >> n >> c;
    cin >> s;
    if (c == 'g') {
        cout << 0 << '\n';
        return;
    }

    int res = 0;
    stack<int>st;
    for (int i = 0; i < n; ++i) {
        if (s[i] == c) st.push(i);
        while (!st.empty() && s[i] == 'g') {
            res = max(res, i - st.top());


            st.pop();

        }
    }
    if (!st.empty()) {
        int start = st.top();
        for (int i = 0, flag = 0; i < n && flag == 0; ++i) {
            while (!st.empty() && s[i] == 'g') {
                res = max(res, n - st.top() + i);
                st.pop();
                flag = 1;
            }
        }
    }

    cout << res << '\n';
}


int main() {
    int n;
    cin >> n;
    while (n--) test() ;
}
