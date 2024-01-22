#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll t;

void test() {
    int n, k;
    std::string s;
    cin >> n >> k;
    cin >> s;
    // first check for periodicity
    map<int, char>mp;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '?') {
            if (mp.find(i % k) != mp.end()) {
                s[i] = mp[i % k];
            }
            continue;
        }
        int key = i % k;
        if (mp.find(key) != mp.end()) {
            if (mp[key] != s[i]) {
                cout << "NO\n";
                return;
            }
        } else {
            mp[key] = s[i];
        }
    }
    mp.clear();
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == '?') {
            if (mp.find(i % k) != mp.end()) {
                s[i] = mp[i % k];
            }
            continue;
        }
        int key = i % k;
        if (mp.find(key) != mp.end()) {
            if (mp[key] != s[i]) {
                cout << "NO\n";
                return;
            }
        } else {
            mp[key] = s[i];
        }
    }
    int l = 0;
    int zc = 0;
    int oc = 0;
    // check first for invalid
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            ++oc;
        } else if (s[i] == '0') {
            ++zc;
        }
        if (i - l + 1 > k) {
            if (s[l] == '1') {
                --oc;
            } else if (s[l] == '0') {
                --zc;
            }
            ++l;
        }
        if (i - l + 1 == k) {
            if (oc > k/2 || zc > k/2) {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
}
int main() {
    cin >> t;
    while (t--) test();
}