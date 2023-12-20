#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll t;

int main() {
    cin >> t;
    string res = "codeforces";
    vector<int>nums(10, 1);
    ll cur = 1;
    for (int i = 0; cur < t; ++i, i %= 10) {
        cur /= nums[i];
        ++nums[i];
        cur *= nums[i];
    }

    cout << res << '\n';
}

