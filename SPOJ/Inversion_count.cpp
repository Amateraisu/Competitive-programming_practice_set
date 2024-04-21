#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T>
using Tree =
        tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


using ll = long long;
int main() {
    int n;
    cin>> n;
    while (n--) {
        Tree<ll>tree;
        int m;
        cin >> m;
        ll res = 0;
        for (int i = 0; i < m; ++i) {
            ll x;
            cin >> x;
            res += tree.size() - tree.order_of_key(x);
            tree.insert(x);
        }
        cout << res << '\n';
    }
}
