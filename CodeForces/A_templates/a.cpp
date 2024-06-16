#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll t;


void test() {
    int n;
    cin >> n;
    vector<int>A(n, 0);
    for (int i = 0; i < n; ++i) cin >> A[i];
    ll mini = 1e9 + 7;
    for (int i = 0; i < n - 1; ++i) {
        ll maxi = max(A[i], A[i + 1]);
        mini = min(mini, maxi);

    }

    std::cout << mini - 1 << '\n';

    return;

}
int main() {
    cin >> t;
    while (t--) test();
}