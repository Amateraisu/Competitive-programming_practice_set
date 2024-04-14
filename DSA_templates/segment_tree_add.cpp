#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
using ll = long long;

class seg {
private:
    std::vector<ll> tree;
    int n;

public:
    seg(const std::vector<ll>& A) {
        n = A.size();
        int height = (int)ceil(log2(n));
        int max_size = 2 * (int)pow(2, height) - 1;
        tree.resize(max_size, 0);
        build(A, 0, n - 1, 0);
    }

    void build(const std::vector<ll>& A, int start, int end, int node) {
        if (start == end) {
            tree[node] = A[start];
        } else {
            int mid = (start + end) / 2;
            build(A, start, mid, 2 * node + 1);
            build(A, mid + 1, end, 2 * node + 2);
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }

    void add(int idx, ll value) {
        update(0, n - 1, 0, idx, value);
    }

    void update(int start, int end, int node, int idx, ll value) {
        if (start == end) {
            tree[node] += value;
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid)
                update(start, mid, 2 * node + 1, idx, value);
            else
                update(mid + 1, end, 2 * node + 2, idx, value);
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }

    ll sum(int l, int r) {
        return query(0, n - 1, 0, l, r);
    }

    ll query(int start, int end, int node, int l, int r) {
        if (r < start || end < l)
            return 0;
        if (l <= start && end <= r)
            return tree[node];
        int mid = (start + end) / 2;
        ll left_sum = query(start, mid, 2 * node + 1, l, r);
        ll right_sum = query(mid + 1, end, 2 * node + 2, l, r);
        return left_sum + right_sum;
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    std::vector<ll> A(n, 0);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        A[i] = x;
    }
    seg st(A);
    for (int i = 0; i < q; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            st.add(b, c);
        } else {

            cout << st.sum(b, c) << '\n';
        }
    }
    return 0;
}
