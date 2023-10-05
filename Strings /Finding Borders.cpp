#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll R = 31, MOD = 1e9 + 7;

string S;
ll H[1000005], P = 1;

int main() {
    cin >> S;
    for (int i = 0; i < S.size(); i++)
        H[i] = ((i == 0 ? 0 : H[i - 1]) * R + (ll)S[i]) % MOD;

    for (int k = 1; k < (int)S.size(); k++) {
        P = (P * R) % MOD;
        ll suf = (H[S.size() - 1] - (P * H[S.size() - k - 1]) % MOD + MOD) % MOD;
        if (H[k - 1] == suf)
            cout << k << ' ';
    }
    cout << '\n';
}