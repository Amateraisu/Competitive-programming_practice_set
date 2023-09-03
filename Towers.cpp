#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

long long x, n;
int res = 0;
int main() {
    cin >> n;
    multiset<long long>set;
    for (int i = 0; i < n ;i++) {

        cin >> x;
        if (set.upper_bound(x) == set.end()) {
            res++;
            set.insert(x);
        } else {
            auto it = set.upper_bound(x);
            set.erase(it);
            set.insert(x);
        }

    }
    cout << res << '\n';
    return 0;
}