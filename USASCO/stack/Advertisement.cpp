#include <bits/stdc++.h>
using namespace std;
using ll = long long;



int main() {
//    freopen("Input.txt", "r", stdin);
//    freopen("Output.txt", "w", stdout);
//    freopen("Error.txt", "w", stderr);
    int n;
    cin >> n;
    vector<ll>A(n);
    for (int i = 0; i < n; ++i) cin >> A[i];
    vector<pair<ll, ll>>s;
    ll res = 0;
    for (int i = 0 ; i < n; ++i) {
        res = max(res, A[i]);
        ll cur = A[i];
        ll start = i;
        while (!s.empty() && A[i] <= s.back().second) {
            res = max(res, (i - s.back().first) * s.back().second);
            start = s.back().first;
            s.pop_back();
        }
        s.push_back(make_pair(start, cur));

//        cout << "lk " << s.back().first << ' ' << s.back().second << ' ' << res << '\n';
    }

    // for those which remained in the stack, which means the height can be extended all the way to the end of the array
    ll cur = -1;
    for (auto & p : s) {
        res = max(res, p.second * (n - p.first));
    }
    cout << res << '\n';

    return 0;
}