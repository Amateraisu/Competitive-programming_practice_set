#include <bits/stdc++.h>
using ll = long long;

constexpr int maxN = 2e5 + 1;
int low[maxN * 4];
int high[maxN * 4];
ll arr[maxN*4];
int nums[maxN];
int n, q;
ll k, a, b;

void pull(int i) {
    arr[i] = arr[i * 2] + arr[i * 2 + 1];
}

void init(int index, int l, int r) {
    low[index] = l;
    high[index] = r;
    if (l == r) {
        arr[index] = nums[l];
        return ;

    }
    int m = l + (r - l)/2;
    init(index * 2, l, m);
    init(index * 2 + 1, m + 1, r);
    pull(index);
}

void update(int i, int l, int r, int v) {
    if (l <= low[i] && high[i] <= r) {
        arr[i] = v;
        return;
    }
    if (l > high[i] || r < low[i]) return;
    update(2 *i , l, r, v);
    update(2 * i + 1, l, r, v);
    pull(i);
}

ll query(int i, int l, int r) {
    if (l <= low[i] && high[i] <= r ) return arr[i];
    if (l > high[i] || r < low[i]) return 0;
    ll left = query(2 * i, l, r);
    ll right = query(2 *i + 1, l, r);
    return left + right;
}

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    init(1, 1, n);
    for (int i = 0; i < q; i++) {
        scanf("%lld %lld %lld", &k , &a, &b);
        if (k == 1) {
            update(1, a, a, b);
        } else {
            printf("%lld\n", query(1, a, b));
        }
    }






    return 0;
}