#include <bits/stdc++.h>
using namespace std;



int main() {
    string s;
    cin >> s;
    int n = s.size();
    stack<char>st;
    int res = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == ')') {
            if (!st.empty()) {
                st.pop();
                ++res;
            }
        } else {
            st.push('(');
        }
    }
    cout << res << '\n';
}
