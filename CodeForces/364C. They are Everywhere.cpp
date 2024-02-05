#include <bits/stdc++.h>

using namespace std;


int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    set<char>st;
    for (int i = 0; i < n; ++i)st.insert(s[i]);
    int maxi = st.size();
    int res = 0x3f3f3f3f;
    int ptr1 = 0 ;
    set<char>t;
    map<char, int>mp;
    int l = 0;
    for (int i= 0; i < n; ++i) {
        ++mp[s[i]];
        while (mp[s[l]] > 1) {
            --mp[s[l]];
            ++l;
        }
        int have = 0;
        for (auto& [a, b] : mp) {
            if (b > 0) ++have;
        }
        if (have == maxi) {
            res = min(res, i - l + 1);
        }
    }

    std::cout << res << '\n';
}
