
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

int main() {
    int x, n;
    cin >> x >> n;
    multiset<int>lengths;
    lengths.insert(x);// the length created by x
    set<int>positions;
    positions.insert(0);
    positions.insert(x);
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        positions.insert(t);
        auto it = positions.find(t);
        int lower = *prev(it);
        int upper = *next(it);
        lengths.erase(lengths.find(upper - lower));
        lengths.insert(upper - t);
        lengths.insert(t - lower);

        cout << *lengths.rbegin() << ' ';
    }


    return 0;
}