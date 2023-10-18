#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int maxN = 2e5 + 1;

ll k, a, b;
ll x;
int n, q;
ll lo[maxN*4], hi[maxN*4], arr[maxN*4];

void pull(int i) {
    arr[i] = arr[2 *i] + arr[2*i + 1];
}

void init(int i, int l, int r) {
    lo[i] = l;
    hi[i] = r;
    if (l == r) {
        scanf("%lld", &arr[i]);
        return;
    }
    int m = l + (r - l)/2;
    init(2 * i, l, m);
    init(2 * i + 1, m + 1, r);
    pull(i);
}

void update(int i, int l, int r, int v) {
    if (l <= lo[i] && hi[i] <= r) {
        arr[i] = v;
        return;
    }
    if (l > hi[i] || r < lo[i]) return;
    update(2 *i , l, r, v);
    update(2 * i + 1, l, r, v);
    pull(i);
}

ll query(int i, int l, int r) {
    if (l <= lo[i] && hi[i] <= r ) return arr[i];
    if (l > hi[i] || r < lo[i]) return 0;
    ll left = query(2 * i, l, r);
    ll right = query(2 *i + 1, l, r);
    return left + right;
}

int main(){
    scanf("%d %d", &n, &q);
    init(1, 1, n);
    for (int i = 0; i < q; i++) {
        scanf("%lld %lld %lld", &k, &a, &b);
        if (k == 1) {
            update(1, a, a, b);
        } else {
            printf("%lld\n", query(1, a, b));
        }
    }
    return 0;
}
