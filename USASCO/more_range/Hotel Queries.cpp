#include <bits/stdc++.h>
using namespace std;


template <typename T>
class MaxSegmentTree {
private:
    const T DEFAULT = 0;

    vector<T> segtree;
    int len;

public:
    MaxSegmentTree(int len) : len(len), segtree(len * 2, DEFAULT) {}

    void set(int ind, T val) {
        ind += len;
        segtree[ind] = val;
        for (; ind > 1; ind /= 2) {
            segtree[ind / 2] = max(segtree[ind] , segtree[ind ^ 1]);
        }
    }
    // [start, end)
    T range_sum(int start, int end) {
        T mini = DEFAULT;
        for (start += len, end += len; start < end; start /= 2, end /= 2) {
            if (start % 2 == 1) { mini = max(mini, segtree[start++]); }
            if (end % 2 == 1) { mini = max(mini, segtree[--end]); }
        }
        return mini;
    }
};


int main() {
    int n, x;
    cin >> n >> x;
    vector<int>A(n, 0);
    vector<int>Q(x, 0);
    for (int i = 0; i < n; ++i) cin >> A[i];
    for (int i = 0; i < x; ++i) cin >> Q[i];
    MaxSegmentTree<int>T(n);
    for (int i = 0; i < n; ++i) T.set(i, A[i]);
    auto can = [&](int m, int x) {
        int maxi = T.range_sum(0, m);
        return maxi >= x;
    };
    for (int i = 0; i < x; ++i) {
        int left = 0;
        int right = n - 1;
        int res = n + 1;
        while (left <= right) {
            int mid = left + (right - left)/2;
            if (can(mid + 1, Q[i])) {
                res = min(res, mid);
                right = mid -1;
            } else {
                left = mid + 1;
            }
        }
        if (res < n) T.set(res, T.range_sum(res, res + 1) - Q[i]);
        if (res >= n) {
            cout << 0 << '\n';
        } else {
            cout << ++res << '\n';
        }


    }
    cout << '\n';
}