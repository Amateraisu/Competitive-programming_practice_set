#include <bits/stdc++.h>
using namespace std;
int t, n, k;


void test() {
    cin >> n >> k;
    vector<int>res(n, 0);
    int cur = n - k;
    for (int i = 0; i < k; ++i, ++cur) {
        res[i] = cur;
    }
    cur = n - k;
    for (int i = k; i < n; ++i, --cur) {
        res[i] = cur;
    }
    for (int i = 0; i < n; ++i) {
        cout << res[i] << ' ';
    }
    cout << '\n';

}



int main() {
    cin >> t;
    while (t--) test();
}
