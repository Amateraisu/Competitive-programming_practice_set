#include <bits/stdc++.h>
using namespace std;






int main() {
//    freopen("Input.txt", "r", stdin);
//    freopen("Output.txt", "w", stdout);
//    freopen("Error.txt", "w", stderr);
    int n;
    cin >> n;
    vector<int>A(n, 0);
    vector<int>L(n, 0);
    vector<int>R(n, 0);
    vector<int>sz(n, 0);
    vector<pair<int, int>>s;
    for (int i = 0; i < n; ++i) cin >> A[i];
    // to build LHS.
    for (int i = 0; i < n; ++i) {
        L[i] = i;
        while (!s.empty() && s.back().second >= A[i]) {
            s.pop_back();
        }
        if (s.empty()) {
            L[i] = 0;
        } else {
            L[i] = s.back().first + 1;
        }
        s.push_back(make_pair(i, A[i]));

    }
    s.clear();
    for (int i = n - 1; i >= 0; --i) {
        R[i] = i;
        while (!s.empty() && s.back().second >= A[i]) {
            s.pop_back();
        }
        if (s.empty()) {
            R[i] = n - 1;
        } else {
            R[i] = s.back().first - 1;
        }
        s.push_back(make_pair(i, A[i]));


    }
    // testing
//    cout << "LHS\n";
//    for (int x : L) {
//        cout << x << '\n';
//    }
//    cout << "RHS\n";
//    for (int x : R) {
//        cout << x << '\n';
//    }
    for (int i = 0 ; i < n; ++i) {
        sz[i] = R[i] - L[i] + 1;
    }
    std::unordered_map<int, int>mp;
    for (int i = 0; i < n; ++i) {
        int x = sz[i];
        mp[x] = max(mp[x], A[i]);
    }
    vector<int>res(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        res[i] = mp[i];
    }
    int ret = -1;
    // if dont have, then go and find the previous answer.
    // but for base case of sz = n, there is always an answer.

    for (int i = n; i >= 1; --i) {
        ret = max(ret, mp[i]);
        res[i] = ret;
    }
    for (int i = 1; i <= n; ++i) {
        cout << res[i] << ' ';
    }
}
