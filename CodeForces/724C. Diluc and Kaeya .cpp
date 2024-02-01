#include <bits/stdc++.h>
using namespace std;

pair<int, int> get(int a, int b) {
    int g = gcd(a, b);
    a/= g;
    b/=g;

return {a, b};
}


void test() {

    int n;
    cin >> n;
    std::string s;
    cin >> s;
    int a = 0, b = 0;
    map<pair<int, int>, int>mp;
    vector<pair<int, int>>dp;
    for (int i = 0 ; i < n; ++i) {
        if (s[i] == 'D') {
            ++a;
        } else {
            ++b;
        }

        std::cout << ++mp[get(a, b)] << '\n';

    }
}