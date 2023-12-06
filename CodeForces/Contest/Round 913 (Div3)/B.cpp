#include <bits/stdc++.h>
using namespace std;
using p = pair<int, char>;  // Change to pair

using ll = long long;
ll t;

void test() {
    string s;
    cin >> s;
    int n = s.size();
    set<p> u;
    set<p> l;
    for (int i = 0; i < n; ++i) {
        char c = s[i];
        if (c == 'b') {
            if (l.size() > 0) {
                auto it = l.rbegin();
                l.erase(next(it).base());
            }
        } else if (c == 'B') {
            if (u.size() > 0) {
                auto it = u.rbegin();
                u.erase(next(it).base());
            }
        } else {
            if (isupper(c)) {
                u.insert({i, c});
            } else {
                l.insert({i, c});
            }
        }
    }
    string res;
    auto ptr1 = u.begin();
    auto ptr2 = l.begin();
    while (ptr1 != u.end() && ptr2 != l.end()) {
        int i1 = ptr1->first;  // Access first element of the pair
        string c1 = string(1, ptr1->second);  // Access second element of the pair
        int i2 = ptr2->first;  // Access first element of the pair
        string c2 = string(1, ptr2->second);  // Access second element of the pair
        if (i1 < i2) {
            res += c1;
            ++ptr1;
        } else {
            res += c2;
            ++ptr2;
        }
    }
    while (ptr1 != u.end()) {
        string c1 = string(1, ptr1->second);  // Access second element of the pair
        ++ptr1;
        res += c1;
    }
    while (ptr2 != l.end()) {
        string c1 = string(1, ptr2->second);  // Access second element of the pair
        res += c1;
        ++ptr2;
    }
    cout << res << '\n';
}

int main() {
    cin >> t;
    while (t--) test();
    return 0;
}
