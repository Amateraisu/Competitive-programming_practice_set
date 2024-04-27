#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T>
using Tree =
        tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
using ll = long long;
constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
int mp[200001]; // stick to arrays whenever possible.
int main() {
    Tree<pair<ll, ll>>tree;
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        ll k;
        cin >> k;
        mp[i + 1] = k;
        tree.insert(make_pair(k, i + 1));
    }
    for (int i = 0; i < q; ++i) {
        char a;
        int b, c;
        cin >> a >> b >> c;
        if (a == '!') {
            tree.erase({mp[b], b});
            mp[b] = c;
            tree.insert({mp[b], b});

        } else {
            int l = tree.order_of_key({c, INF});
            int r = tree.order_of_key({b - 1, INF});
            cout << l - r << '\n';
        }
    }

}