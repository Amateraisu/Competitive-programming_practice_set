#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<int>A;

bool dfs(ll num) {
    if (num == 1) return true;

    ll res = false;
    for (int x : A) {
        if (num == x) return true;
        if (num % x == 0) {
            res |= dfs(num / x);
        }
    }
    return res;
}


void test() {
    ll n;
    cin >> n;
    // do a dfs to see if anyone becomes a candidate or not.
    if (dfs(n)) {
        cout <<"YES\n";
    } else {
        cout << "NO\n";
    }
}


int main() {

    auto can = [](int a) {
        string s = std::to_string(a);
        for (auto& x : s) {
            if (x != '0' && x != '1') return false;
        }
        return true;
    };
    int n;
    for (int i = 1; i <= 1e6; ++i) {
        if (can(i)) A.push_back(i);
    }
    cin >> n;
    while (n--) test();
}