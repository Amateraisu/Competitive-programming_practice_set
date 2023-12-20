#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll t, n;


void solve() {
    cin >> n;
    map<int, vector<int>>mp;
    int x;
    for (int i = 2; i <= n; ++i) {
        cin >> x;
        mp[x].push_back(i);
    }
}


int main() {
    cin >> t;
    while (t--) solve();
}