#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void test() {
    int n, m;
    cin >> n >> m;
    vector<ll>A(n, 0);
    vector<ll>B(m, 0);

    for (int i = 0; i < n; ++i) cin >> A[i];
    for (int i = 0; i < m; ++i) cin >> B[i];
    vector<vector<pair<ll, ll>>>buckets(31);
    // divide them into buckets
    for (int i = 0; i < n; ++i) {
        for (int j = 30; j >= 0; --j) {
            if ((A[i] % (1 << j)) == 0) {
                buckets[j].push_back({A[i], i});
                break;
            }
        }
    }
    for (int x : B) {
        // everything >= this bit number gets shifted to the bit at x - 1
        for (int i = x; i <= 30; ++i) {
            while (buckets[i].size() > 0) {
                auto p = buckets[i].back();
                p.first += (1 << (x - 1));
                buckets[i].pop_back();
                buckets[x - 1].push_back(p);
            }
        }
    }
    vector<ll>ret(n , 0);
    for (int i = 0; i <= 30; ++i) {
        for (auto p : buckets[i]) {
            ret[p.second] = p.first;
        }
    }
    for (ll x : ret) cout << x << ' ';
    cout << '\n';
}






int main() {
    int n;
    cin >> n;
    while (n--) test();
}
