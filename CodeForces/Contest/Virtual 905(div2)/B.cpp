#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int INF = 0x3f3f3f3f;
void test() {
    int n, k;
    cin >> n >> k;
    vector<int>A(n, 0);
    int c = 0;
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
        if (A[i] % 2 == 0) ++c;
    }
    int res = INF;
    for (int i = 0; i < n; ++i) {
        int x = A[i];
        res = min(res, (k - (x % k)) % k);
    }
    int try2 = INF;
    if (k == 4) {
        // can try getting 2 evens instead.
        if (c == 1 && n >= 2) {
            try2 = 1;
        } else if (c == 0 && n >= 2) {
            try2 = 2;
        } else if (c >= 2) {
            try2 = 0;
        }
    }
    cout << min(res ,try2) << '\n';

}



int main() {
    int n;
    cin >> n;
    while (n--) test();
}