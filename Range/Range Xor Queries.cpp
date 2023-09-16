#include <climits>
#include <iostream>
using ll = long long;
using namespace std;
const int maxN = 2e5, SIZE = 4*maxN;
const int INF = INT_MAX;

int N, Q, t, a, b, lo[SIZE], hi[SIZE], mn[SIZE];

void pull(int i) {
    mn[i] = mn[2 * i] ^ mn[2* i + 1];
    // cout << "BUILDING"  << '\n';
    // cout << mn[2 * i] << '\n';
    // cout << mn[2 * i + 1] << '\n';
    // cout << mn[i] << '\n';
}

void build(int i = 1, int l = 1, int r = N) {
    lo[i] =l  ;
    hi[i] = r;
    if (l == r) {
        cin >> t;
        mn[i] = t;
        return;
    }
    int m = l + (r - l)/2;
    build(2 * i, l, m);
    build(2* i + 1, m + 1, r);
    pull(i);
}

int get(int i , int l , int r) {
    if (l > hi[i] || r < lo[i]) return 0;
    if (l <= lo[i] && hi[i] <= r) return mn[i];
    int left = get(2 * i, l, r);
    int right = get(2 * i + 1, l , r);
    pull(i);
    // cout << " CURRENT " << mn[i] << '\n';
    int res = left ^ right;
    // cout << "QUERYING " << l << ' ' << r <<" " << res << '\n';
    return left ^ right;
}

int main() {
    cin >> N >> Q;
    build();
    for (int i = 0; i < Q; i++) {
        cin >> a >> b;
        cout << get(1, a , b) << '\n';
    }




    return 0;
}