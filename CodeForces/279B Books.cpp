#include <bits/stdc++.h>

using ll = long long;
using namespace std;
ll n, t;
int main() {
    scanf("%lld %lld", &n, &t);
    vector<int>books(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> books[i];
    }
    int cur = 0;
    int l = 0;
    int res = 0;
    for (int r = 0; r < n; ++r) {
        cur += books[r];
        while (cur > t) {
            cur -= books[l];
            ++l;
        }
        res = max(res, r - l + 1);
    }
    cout << res << '\n';



    return 0;
}
