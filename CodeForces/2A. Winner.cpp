#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF = 0x3f3f3f3f3f3f3f3f;

int main() {
    ll res = -INF;
    string ret;
    ll b, n;
    string a;
    cin >> n;
    map<string, ll>mp;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        mp[a] += b;
        if (mp[a] > res) {
            ret = a;
            res = mp[a];
        }
    }

    cout << ret << '\n';
}
