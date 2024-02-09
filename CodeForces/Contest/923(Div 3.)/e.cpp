#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll t;


void test() {
    int n, k;
    cin >> n >> k;
    int l = 1;
    int r = n;
    vector<int>res(n, 0);
    for (int i = 0; i < k; ++i) {
        for (int j = i; j < n; j += k) {
            if (j % 2 == 0) {
                res[j] = l;
                ++l;
            } else {
                res[j] = r;
                --r;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        std::cout << res[i] << ' ';
    }
    std::cout << '\n';



}
int main() {
    cin >> t;
    while (t--) test();
}
