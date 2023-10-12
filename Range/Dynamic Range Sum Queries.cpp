#include <iostream>
using namespace std;
using ll = long long;
constexpr int maxN = 2e5;

ll lo[maxN * 4];
ll hi[maxN *  4];
ll arr[maxN * 4];
int n, q;
ll a, b;
ll k, u;

void pull(int i) {
    arr[i] = arr[2 * i] + arr[2 * i + 1];
}

void init(int index, int l, int r) {
    lo[index] = l;
    hi[index] = r;
    if (l == r) {
        scanf("%lld", &arr[index]);
        return;
    }
    int m = l + (r -l)/2;
    init(index * 2, l, m);
    init(index * 2 + 1, m + 1, r);
    pull(index);
}

void assign(int i, int l, int r, int v) {
    if (l <= lo[i] && hi[i] <= r) {
        arr[i] = v;
        return;
    }
    if (l > hi[i] || r < lo[i]) return;
    assign(2 *i, l, r, v);
    assign(2 * i + 1, l, r, v);
    pull(i);
}
ll query(int i, int l, int r) {
    if (l <= lo[i] && hi[i] <= r) return arr[i];
    if (l > hi[i] || r < lo[i]) return 0;
    ll left = query(2 * i, l , r);
    ll right = query(2 * i + 1, l, r);

    return left + right;
}



int main() {
    scanf("%d %d", &n, &q);
    init(1, 1, n);
    for (int i = 0; i < q; i++) {
        scanf("%lld %lld %lld", &k, &a, &b);
        if (k == 1) {
            assign(1, a, a, b);
        } else {
            printf("%lld\n", query(1, a, b));
        }

    }
    return 0;
}