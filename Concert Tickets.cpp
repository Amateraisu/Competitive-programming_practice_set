#include <iostream>
#include <algorithm>
#include <vector>
#include <set>


using namespace std;
int m, n;

int main() {
    multiset<int> prices;
    cin >> n >> m;
    int x, y;
    for (int i = 0; i < n ;i++) cin >> x, prices.insert(-x);
    for (int j = 0; j < m ; j++) {
        cin >> y;
        if (prices.lower_bound(-y) != prices.end()) {
            cout << -(*prices.lower_bound(-y)) << '\n';
            prices.erase(prices.lower_bound(-y));
        } else {
            cout << "-1" << '\n';
        }
    }
    return 0;
}
