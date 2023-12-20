#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;

int main() {
    map<ll, ll>mp;
    ll a, b;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        if (a == 1) {
            ++mp[b];
            while (mp[b] >= 3  && b <= 40) {
                mp[b] -= 2;
                ++b;
                mp[b] += 1;
            }
        } else {
            bool can = true;
            for (int j = 40; j >= 0; --j) {
                int t = b/(1 << j);
                if (t) b -= (1 << j) * t;

            }
            if (b == 0) {
                cout << "CAN\n";
            } else {
                cout << "NO\n";
            }

        }
    }
    return 0;
}