#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void test() {
    ll n, k;
    cin >> n >> k;

    vector<ll>A(n, 0);
    for (int i = 0; i < n; ++i) cin >> A[i];
    int p1 = 0;
    int p2 = n - 1;
    ll res = 0;
    bool flag = true; // should add one in front
    while (p1 <=  p2) {
        if (flag) {
            if (A[p1] > A[p2]) {
                //back

                flag = true;
                ll c = min(k, A[p2] * 2);
                if (c == A[p2] * 2) {
                    A[p1] -= A[p2];
                    A[p2] = 0;
                    ++res;
                    --p2;
                } else {
                    // not enuf k,
                    break;
                }
            } else {
                ll c= min(k, A[p1] + A[p1] - 1);
                if (c == A[p1] + A[p1] - 1) {
                    flag = false;
                    A[p2] -= (A[p1] - 1);
                    A[p1] = 0;
                    ++res;
                    ++p1;
                } else {
                    break;
                }
            }
        } else {
            if (A[p2] > A[p1]) {

                ll c = min(k, A[p1] * 2);
                if (c == A[p1] * 2) {
                    flag = false;
                    A[p2] -= A[p1];
                    A[p1] = 0;
                    ++res;
                    ++p1;
                } else {
                    // not enuf k,
                    break;
                }
            } else {
                ll c= min(k, A[p2] + A[p2] - 1);
                if (c == A[p2] + A[p2] - 1) {
                    flag = true;
                    A[p1] -= (A[p2] - 1);
                    A[p2] = 0;
                    ++res;
                    --p2;
                } else {
                    break;
                }
            }
        }

    }
    cout << res << '\n';


}


int main() {
    int n;
    cin >> n;
    while (n--) test();
}