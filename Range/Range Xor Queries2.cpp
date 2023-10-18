#include <bits/stdc++.h>
using ll = long long;
using namespace std;

constexpr int maxN = 2e5 + 1;
ll a, b;
int n, q;
ll tree[maxN * 4], lo[maxN * 4], hi[maxN * 4];

void pull(int i) {
    tree[i] = tree[2 *i] ^ tree[2* i + 1];
}

void assign(int i, int l, int r, int v) {
    if (l <= lo[i] && hi[i] <= r) {
        tree[i] = v;
        return;
    }
    if (l > hi[i] || r < lo[i]) return;
    assign(2 * i, l, r, v);
    assign(2 * i + 1, l, r, v);
    pull(i);
}

ll query(int i, int l, int r) {
    if (l <= lo[i] && hi[i] <= r) return tree[i];
    if (l > hi[i] || r < lo[i]) return 0;
    ll left = query(2 * i , l, r);
    ll right = query(2 * i + 1, l , r);
    return left ^ right;
}


void init(int i, int l, int r) {
    lo[i] = l;
    hi[i] = r;
    if (l == r) {
        scanf("%lld", &tree[i]) ;
        return;
    }
    int m = l + (r - l)/2;
    init(2*i, l, m);
    init(2*i + 1, m + 1, r);

    pull(i);
}

int main() {
    scanf("%d %d", &n, &q);
    init(1, 1, n);
    for (int i = 0; i < q; i++) {
        scanf("%lld %lld", &a, &b);
        printf("%lld\n", query(1, a, b));
    }
    return 0;

}