#include <bits/stdc++.h>
using ll = long long;
using namespace std;
constexpr int maxN = 2e5 + 1;
constexpr int maxQ = 2e5 + 1;
int a, b;
int q, n;
ll A[maxN];
ll pref[maxN + 1];

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 1 ; i <= n; i++) {
        scanf("%lld", &A[i]);
    }
    ll cur = 0;

    for (int i = 1; i <= n; i++) {
        cur += A[i];
        pref[i + 1] = cur;
    }
    for (int i = 0; i < q; i++) {
        scanf("%d %d", &a, &b);
        printf("%lld\n", pref[b + 1] - pref[a]);
    }
    return 0;


    return 0;
}
