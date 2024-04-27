#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T>
using Tree =
        tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


int main() {
    Tree<int>tree;
    int n;
    cin >> n;
    vector<int>A(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
        tree.insert(i);
    }
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        --x;
        int pos = *tree.find_by_order(x);
        cout << A[pos] << ' ';
        tree.erase(pos);
    }
    cout << '\n';


}