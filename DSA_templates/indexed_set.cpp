#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T>
using Tree =
        tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // distinct elements only

template <class T>
using TreeDup =
        tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>; // for allow duplicate elements

int main() {
    Tree<int>tree;



    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.erase(1);
    // also supports erase
    // used to find the kth element in here (in here it is sorted)
    std::cout << *tree.lower_bound(3) << '\n';
    std::cout << tree.size() << '\n';
    std::cout << tree.order_of_key(k) << '\n'; //  0 -indexed. what order does a key come in, gives the count of elements STRICTLY lesser than k
    std::cout << tree.find_by_order() << '\n' ; // 0-indexed. what key is at given order.
}