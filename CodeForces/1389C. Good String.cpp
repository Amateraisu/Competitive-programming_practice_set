#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll t;
string s;

void test() {
    cin >> s;
    map<string, int>mp;
    for (int i = 1; i < s.size(); ++i) {
        string s2 = s.substr(i - 1, 2);
        ++mp[s2];
    }
    int maxi = 0;
    for (auto& [a, b]: mp) {
        maxi = max(maxi, b * 2);
    }
    cout << s.size() - maxi << '\n';
}

int main() {
    cin >> t;
    while (t--) test();
}
