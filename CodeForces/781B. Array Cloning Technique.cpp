#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void test() {
    int n;
    cin >> n;
    vector<int>A(n, 0);
    for (int i = 0; i < n; ++i) cin >> A[i];
    map<int, int>cnt;
    ll g = -1;
    for (int x : A) {
        cnt[x]++;
        g = max(g, 1LL * cnt[x]);
    }

    ll cost = 0;
    cost += (n - g);
    while (g < n) {
        ++cost;
        g *= 2;
    }
    cout << cost << '\n';

}

int main() {
    int n;
    cin >> n;
    while (n--) test();
}
