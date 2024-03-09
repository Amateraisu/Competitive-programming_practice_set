#include <bits/stdc++.h>
using namespace std;
using ll = long long;


void test() {
    int n, k;
    cin >> n >> k;
    bool even = ((n - k) % 2) == 0;
    map<char, int>mp;
    string s;
    cin >> s;
    for (char c : s) {
        ++mp[c];
    }
    int oddCount = 0 ;
    for (auto& [a, b] : mp) {
        if (b % 2 != 0) ++oddCount;
    }
    int limit = -1;
    if (!even) {
        oddCount--;
    }
    if (k < oddCount ) {
        cout << "NO\n";
    } else if ((k - oddCount) % 2 != 0) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }

}



int main() {
    int n;
    cin >> n;
    while (n--) test();
}