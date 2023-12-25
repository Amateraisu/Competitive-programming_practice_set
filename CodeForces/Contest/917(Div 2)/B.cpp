#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll t;
string s;
void test() {
    ll n;
    cin >> n;
    cin >> s;
    ll res = 0;
    set<int>set1;
    for (int i = 0; i < n; ++i) {
        char c = s[i];
        set1.insert(c - 'a');
        res += set1.size();

    }
    cout << res << '\n';
}


int main() {
    cin >> t;
    while (t--) test();
}