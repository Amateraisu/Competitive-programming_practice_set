#include <iostream>
#include <vector>
using namespace std;

using std::cout;
using std::endl;
using std::vector;

template <class T>
class SumSegmentTree {
private:
    const T DEFAULT = 0;

    vector<T> segtree;
    int len;

public:
    SumSegmentTree(int len) : len(len), segtree(len * 2, DEFAULT) {}

    void set(int ind, T val) {
        ind += len;
        segtree[ind] += val;
        for (; ind > 1; ind /= 2) {
            segtree[ind / 2] = segtree[ind] + segtree[ind ^ 1];
        }
    }
    // [start, end)
    T range_sum(int start, int end) {
        T sum = DEFAULT;
        for (start += len, end += len; start < end; start /= 2, end /= 2) {
            if (start % 2 == 1) { sum += segtree[start++]; }
            if (end % 2 == 1) { sum += segtree[--end]; }
        }
        return sum;
    }
};

int main() {
    int n;
    int q;
    std::cin >> n >> q;
    vector<int>A(n, 0);
    for (int i = 0; i < n; ++i) cin >> A[i];
    SumSegmentTree<long long> segtree(n + 1);
    for (int i = 0; i < n; ++i) {
        segtree.set(i, A[i]);
        segtree.set(i + 1, -A[i]);
    }

    for (int i = 0; i < q; i++) {
        int type, a, b, c;
        std::cin >> type;
        if (type == 1) {
            cin >> a >> b >> c;

            segtree.set(a - 1, c);
            segtree.set(b, -c);
        } else if (type == 2) {
            cin >> b;
            cout << segtree.range_sum(0, b) << '\n';
        }
    }
}