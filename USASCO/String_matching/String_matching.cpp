#include <bits/stdc++.h>
using namespace std;

vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

int main() {
    string s;
    string s2;
    cin >> s >> s2;
    int res = 0;
    string s3 = s2 + "#" + s;
    vector<int>p = prefix_function(s3);
    for (int i = 0; i < p.size(); ++i) {
        if (p[i] == s2.size()) {
            ++res;
        }
    }
    cout << res << '\n';
}
