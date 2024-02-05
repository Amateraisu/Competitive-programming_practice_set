#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int t;
    cin >> t;
    vector<string>v;
    std::string s;
    auto c = [&](string& a, string& b) {
        int ptr1 = 0;
        int g = max(a.size(), b.size());
        ll s1 = 0, s2 = 0;
        while (ptr1 < g) {
            if (ptr1 >= a.size()) {
                s1 += 26;
            } else {
                s1 += a[ptr1] - 'a';
            }
            if (ptr1 >= b.size()) {
                s2 += 26;
            } else {
                s2 += b[ptr1] - 'a';
            }
            ++ptr1;
        }
        return s1 < s2;

    };
    while (t--) {
        cin >> s;
        v.push_back(s);
    }
    sort(v.begin(), v.end(), c);
    string r;
    for (auto& cs : v) {
        r += cs;
    }
    std::cout << r << '\n';
}
