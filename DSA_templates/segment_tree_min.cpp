#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using std::cout;
using std::endl;
using std::vector;
using std::min;
template <typename T>
class MinSegmentTree {
private:
    const T DEFAULT = 0x3f3f3f3f3f3f3f3f;

    vector<T> segtree;
    int len;

public:
    MinSegmentTree(int len) : len(len), segtree(len * 2, DEFAULT) {}

    void set(int ind, T val) {
        ind += len;
        segtree[ind] = val;
        for (; ind > 1; ind /= 2) {
            segtree[ind / 2] = min(segtree[ind] , segtree[ind ^ 1]);
        }
    }

    T range_sum(int start, int end) {
        T mini = DEFAULT;
        for (start += len, end += len; start < end; start /= 2, end /= 2) {
            if (start % 2 == 1) { mini = min(mini, segtree[start++]); }
            if (end % 2 == 1) { mini = min(mini, segtree[--end]); }
        }
        return mini;
    }
};

int main() {
    int arr_len;
    int query_num;
    std::cin >> arr_len >> query_num;

    MinSegmentTree<long long> segtree(arr_len);
    for (int i = 0; i < arr_len; i++) {
        int n;
        std::cin >> n;
        segtree.set(i, n);
    }

    for (int q = 0; q < query_num; q++) {
        int type, arg1, arg2;
        std::cin >> type >> arg1 >> arg2;
        if (type == 1) {
            segtree.set(arg1 - 1, arg2);
        } else if (type == 2) {
            cout << segtree.range_sum(arg1 - 1, arg2) << '\n';
        }
    }
}