#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n, k;
    cin >> n >> k;
    vector<ll>A(n, 0);
    for (int i = 0; i < n; ++i) cin >> A[i];
    vector<ll>L;
    ll res = 0;
    vector<ll>R;
    for (int i = 0; i < n/2; ++i) L.push_back(A[i]);
    for (int i = n/2; i < n; ++i) R.push_back(A[i]);
    auto calc_sub = [](vector<ll>& vec, std::map<ll, ll>& mp) {
        int n = vec.size();
        for (int i = 0; i < (1 << n); ++i) {
            // for this mask, do calc
            ll sum = 0;
            for (int j = 0; j < n; ++j) {
                if ((1 << j) & i) {
                    sum += vec[j];
                }
            }
            mp[sum]++;
        }
    };
    std::map<ll , ll> l ,r;
    calc_sub(L, l);
    calc_sub(R, r);
    for (auto& [a, b]: l) {
        res += b * (r[k - a]);
    }
    cout << res << '\n';


}
