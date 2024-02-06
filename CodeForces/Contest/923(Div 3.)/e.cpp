#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll t;


void test() {
    int n, k;
    cin >> n >> k;
    vector<int>res(n, 0);
    bool drop = true;
    int s1 = 1;
    int s2 = n;
    vector<int>v(n + 1, 0);
    res[n - 1] = n/2;
    res[n - 2] = n/2 + 1;
    v[n/2] = 1;
    v[n/2 + 1] = 1;
    bool rise = true;
    for (int i = n - 1; i - k >= 0; --i) {
        if (!rise) {
            rise = true;
            res[i - k] = res[i] - 1;
            v[res[i] - 1] = 1;
        } else {
            rise = false;
            res[i - k] = res[i] + 1;
            v[res[i] + 1] = 1;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (res[i] == 0) {
            for (int j = 1; j <=n; ++j) {
                if (v[j] == 0) res[i] = j;
                break;
            }
            break;
        }
    }

    // checking
    int mini = 0x3f3f3f3f;
    int maxi = -1;
    for (int i = 0; i < n - k; ++i) {
        int cur = 0;
        for (int j = 0; j < k; ++j) {
            cur += res[i + j];
        }
        mini = min(mini, cur);
        maxi = max(maxi, cur);
    }
    std::cout << "DIFF " << maxi - mini << '\n';

    for (int i = 0; i < n; ++i) {
        std::cout << res[i] << ' ' << '\n';
    }



}
int main() {
    cin >> t;
    while (t--) test();
}
